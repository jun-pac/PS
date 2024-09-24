import os
import gc
import time
import uuid
import argparse
import datetime
import numpy as np

import torch
import torch.nn.functional as F

from model import *
from new_utils import *



def main(args):
    if args.seed > 0:
        set_random_seed(args.seed)
    
    name="new_"+args.name
    name=name+'_'+args.mode
    if(args.extra_embedding):
        name=name+'_emb'
    else:
        name=name+'_noemb'
    if(args.hidden!=512):
        name=name+str(args.hidden)
    if(args.debug):
        name=name+"_debug"
    f_log=open('./txtlog/'+name+'.txt','a')
    
    g, init_labels, num_nodes, n_classes, train_nid, val_nid, test_nid, evaluator, paper_year = load_dataset(args,f_log,args.time_bit)
    
    # =======
    # rearange node idx (for feats & labels)
    # =======

    train_node_nums = len(train_nid)
    valid_node_nums = len(val_nid)
    test_node_nums = len(test_nid)
    trainval_point = train_node_nums
    valtest_point = trainval_point + valid_node_nums
    total_num_nodes = len(train_nid) + len(val_nid) + len(test_nid)

    if total_num_nodes < num_nodes:
        flag = torch.ones(num_nodes, dtype=bool)
        flag[train_nid] = 0
        flag[val_nid] = 0
        flag[test_nid] = 0
        extra_nid = torch.where(flag)[0]
        print(f'Find {len(extra_nid)} extra nid for dataset {args.dataset}')
        f_log.write(f'Find {len(extra_nid)} extra nid for dataset {args.dataset}\n')
        f_log.flush()
    else:
        extra_nid = torch.tensor([], dtype=torch.long)

    init2sort = torch.cat([train_nid, val_nid, test_nid, extra_nid])
    sort2init = torch.argsort(init2sort)
    assert torch.all(init_labels[init2sort][sort2init] == init_labels)
    labels = init_labels[init2sort]
    
    #print(f"max(paper_year[train_nid]) : {max(paper_year[train_nid])} | min(paper_year[train_nid]) : {min(paper_year[train_nid])}")
    #print(f"max(paper_year[val_nid]) : {max(paper_year[val_nid])} | min(paper_year[val_nid]) : {min(paper_year[val_nid])}")
    #print(f"max(paper_year[test_nid]) : {max(paper_year[test_nid])} | min(paper_year[test_nid]) : {min(paper_year[test_nid])}")
    #f_log.write(f"max(paper_year[train_nid]) : {max(paper_year[train_nid])} | min(paper_year[train_nid]) : {min(paper_year[train_nid])}\n")
    #f_log.write(f"max(paper_year[val_nid]) : {max(paper_year[val_nid])} | min(paper_year[val_nid]) : {min(paper_year[val_nid])}\n")
    #f_log.write(f"max(paper_year[test_nid]) : {max(paper_year[test_nid])} | min(paper_year[test_nid]) : {min(paper_year[test_nid])}\n")
    #f_log.flush()
    # train : 2010~2017 | valid : 2018 | test : 2019
    more_train_idx=[]
    if args.messi:
        for idx in range(len(train_nid)):
            if (paper_year[train_nid[idx]]>=2016):
                more_train_idx.append(idx)
    if args.messi2017:
        for idx in range(len(train_nid)):
            if (paper_year[train_nid[idx]]>=2017):
                more_train_idx.append(idx)
    more_train_idx=torch.tensor(more_train_idx).to(torch.long)
    print(f"len(more_train_idx) : {len(more_train_idx)} | len(train set) : {len(train_nid)+len(more_train_idx)}")
    f_log.write(f"len(more_train_idx) : {len(more_train_idx)} | len(train set) : {len(train_nid)+len(more_train_idx)}\n")
    f_log.flush()
    # =======
    # features propagate alongside the metapath
    # =======
    prop_tic = datetime.datetime.now()
    if args.dataset in ['ogbn-proteins', 'ogbn-products']: # homogeneous
        tgt_type = 'hop_0'

        g.ndata['hop_0'] = g.ndata.pop('feat')
        for hop in range(args.num_hops):
            g.update_all(fn.copy_u(f'hop_{hop}', 'm'), fn.mean('m', f'hop_{hop+1}'))
        keys = list(g.ndata.keys())
        print(f'Involved feat keys {keys}')
        f_log.write(f'Involved feat keys {keys}\n')
        f_log.flush()
        feats = {k: g.ndata.pop(k) for k in keys}

    elif args.dataset in ['ogbn-arxiv', 'ogbn-papers100M']: # single-node-type & double-edge-types
        tgt_type = 'P'

        for hop in range(1, args.num_hops + 1):
            for k in list(g.ndata.keys()):
                if len(k) == hop:
                    g['cite'].update_all(
                        fn.copy_u(k, 'msg'),
                        fn.mean('msg', f'm{k}'), etype='cite')
                    g['cited_by'].update_all(
                        fn.copy_u(k, 'msg'),
                        fn.mean('msg', f't{k}'), etype='cited_by')

        keys = list(g.ndata.keys())
        print(f'Involved feat keys {keys}')
        f_log.write(f'Involved feat keys {keys}\n')
        f_log.flush()
        feats = {k: g.ndata.pop(k) for k in keys}

    elif args.dataset == 'ogbn-mag': # multi-node-types & multi-edge-types
        tgt_type = 'P'

        extra_metapath = [] # ['AIAP', 'PAIAP']
        extra_metapath = [ele for ele in extra_metapath if len(ele) > args.num_hops + 1]

        print(f'Current num hops = {args.num_hops}')
        f_log.write(f'Current num hops = {args.num_hops}\n')
        f_log.flush()
        if len(extra_metapath):
            max_hops = max(args.num_hops + 1, max([len(ele) for ele in extra_metapath]))
        else:
            max_hops = args.num_hops + 1

        # compute k-hop feature
        g = hg_year_propagate(g, tgt_type, args.num_hops, max_hops, extra_metapath, args.mode, f_log, args.debug, echo=args.debug)
        if(args.debug):
            print(f"DEBUG0 | type(g) : {type(g)} | g : {g}")
            f_log.write(f"DEBUG0 | type(g) : {type(g)} | g : {g}\n")
            f_log.flush()

        feats = {}
        keys = list(g.nodes[tgt_type].data.keys())
        print(f'Involved feat keys {keys}')
        f_log.write(f'Involved feat keys {keys}\n')
        f_log.flush()
        # Involved feat keys ['P', 'PA', 'PF', 'PP', 'PAI', 'PAP', 'PFP', 'PPA', 'PPF', 'PPP']
        for k in keys:
            feats[k] = g.nodes[tgt_type].data.pop(k)
            if(args.debug):
                print(f"DEBUG | k : {k} | type(k) : {type(k)} | type(feats[k]) : {type(feats[k])} | feats[k].shape : {feats[k].shape}")
                f_log.write(f"DEBUG | k : {k} | type(k) : {type(k)} | type(feats[k]) : {type(feats[k])} | feats[k].shape : {feats[k].shape}\n")
                f_log.flush()

            # torch.Size([736389, 128]) for P ... P and torch.Size([736389, 256]) for P ... others.
            
        g = clear_hg(g, echo=args.debug)
    else:
        assert 0

    feats = {k: v[init2sort] for k, v in feats.items()}

    prop_toc = datetime.datetime.now()
    print(f'Time used for feat prop {prop_toc - prop_tic}')
    f_log.write(f'Time used for feat prop {prop_toc - prop_tic}\n')
    f_log.flush()
    gc.collect()

    # train_loader = torch.utils.data.DataLoader(
    #     torch.arange(train_node_nums), batch_size=args.batch_size, shuffle=True, drop_last=False)
    # eval_loader = full_loader = []
    all_loader = torch.utils.data.DataLoader(
        torch.arange(num_nodes), batch_size=args.batch_size, shuffle=False, drop_last=False)

    checkpt_folder = f'./output/{args.dataset}/'
    if not os.path.exists(checkpt_folder):
        os.makedirs(checkpt_folder)

    if args.amp:
        scalar = torch.cuda.amp.GradScaler()
    else:
        scalar = None

    device = "cuda:{}".format(args.gpu) if not args.cpu else 'cpu'
    labels_cuda = labels.long().to(device)

    checkpt_file = checkpt_folder + uuid.uuid4().hex
    print(checkpt_file)

    for stage in range(args.start_stage, len(args.stages)):
        epochs = args.stages[stage]

        if len(args.reload):
            pt_path = f'output/ogbn-mag/{args.reload}_{stage-1}.pt'
            assert os.path.exists(pt_path)
            print(f'Reload raw_preds from {pt_path}', flush=True)
            f_log.write(f'Reload raw_preds from {pt_path}\n')
            f_log.flush()
            raw_preds = torch.load(pt_path, map_location='cpu')

        # =======
        # Expand training set & train loader
        # =======
        if stage > 0:
            preds = raw_preds.argmax(dim=-1)
            predict_prob = raw_preds.softmax(dim=1)

            train_acc = evaluator(preds[:trainval_point], labels[:trainval_point])
            val_acc = evaluator(preds[trainval_point:valtest_point], labels[trainval_point:valtest_point])
            test_acc = evaluator(preds[valtest_point:total_num_nodes], labels[valtest_point:total_num_nodes])

            print(f'Stage {stage-1} history model:\n\t' \
                + f'Train acc {train_acc*100:.4f} Val acc {val_acc*100:.4f} Test acc {test_acc*100:.4f}')
            f_log.write(f'Stage {stage-1} history model:\n\t' \
                + f'Train acc {train_acc*100:.4f} Val acc {val_acc*100:.4f} Test acc {test_acc*100:.4f}\n')
            f_log.flush()

            confident_mask = predict_prob.max(1)[0] > args.threshold
            val_enhance_offset  = torch.where(confident_mask[trainval_point:valtest_point])[0]
            test_enhance_offset = torch.where(confident_mask[valtest_point:total_num_nodes])[0]
            val_enhance_nid     = val_enhance_offset + trainval_point
            test_enhance_nid    = test_enhance_offset + valtest_point
            enhance_nid = torch.cat((val_enhance_nid, test_enhance_nid))

            print(f'Stage: {stage}, threshold {args.threshold}, confident nodes: {len(enhance_nid)} / {total_num_nodes - trainval_point}')
            f_log.write(f'Stage: {stage}, threshold {args.threshold}, confident nodes: {len(enhance_nid)} / {total_num_nodes - trainval_point}\n')
            f_log.flush()
            val_confident_level = (predict_prob[val_enhance_nid].argmax(1) == labels[val_enhance_nid]).sum() / len(val_enhance_nid)
            print(f'\t\t val confident nodes: {len(val_enhance_nid)} / {valid_node_nums},  val confident level: {val_confident_level}')
            f_log.write(f'\t\t val confident nodes: {len(val_enhance_nid)} / {valid_node_nums},  val confident level: {val_confident_level}\n')
            f_log.flush()
            test_confident_level = (predict_prob[test_enhance_nid].argmax(1) == labels[test_enhance_nid]).sum() / len(test_enhance_nid)
            print(f'\t\ttest confident nodes: {len(test_enhance_nid)} / {test_node_nums}, test confident_level: {test_confident_level}')
            f_log.write(f'\t\ttest confident nodes: {len(test_enhance_nid)} / {test_node_nums}, test confident_level: {test_confident_level}\n')
            f_log.flush()

            del train_loader
            train_batch_size = int(args.batch_size * len(train_nid) / (len(enhance_nid) + len(train_nid)))
            train_loader = torch.utils.data.DataLoader(
                torch.cat((torch.arange(train_node_nums),more_train_idx),dim=0), batch_size=train_batch_size, shuffle=True, drop_last=False)
            enhance_batch_size = int(args.batch_size * len(enhance_nid) / (len(enhance_nid) + len(train_nid)))
            enhance_loader = torch.utils.data.DataLoader(
                enhance_nid, batch_size=enhance_batch_size, shuffle=True, drop_last=False)
        else:
            train_loader = torch.utils.data.DataLoader(
                torch.cat((torch.arange(train_node_nums),more_train_idx),dim=0), batch_size=args.batch_size, shuffle=True, drop_last=False)

        # =======
        # labels propagate alongside the metapath
        # =======
        label_feats = {}
        if args.label_feats:
            if stage > 0:
                label_onehot = predict_prob[sort2init].clone()
            else:
                label_onehot = torch.zeros((num_nodes, n_classes))
            label_onehot[train_nid] = F.one_hot(init_labels[train_nid], n_classes).float()

            if args.dataset in ['ogbn-proteins', 'ogbn-products']: # homogeneous
                g.ndata['s'] = label_onehot
                for hop in range(args.num_label_hops):
                    g.update_all(fn.copy_u('m'*hop+'s', 'msg'), fn.mean('msg', 'm'*(hop+1)+'s'))
                keys = [k[:-1] for k in g.ndata.keys() if k != 's']
                print(f'Involved label keys {keys}')
                label_feats = {k: g.ndata.pop(k+'s') for k in keys}
                g = clear_hg(g, echo=False)

                # remove self effect on label feats
                mm_diag, mmm_diag = torch.load(f'{args.dataset}_diag.pt')
                diag_values = {'mm': mm_diag, 'mmm': mmm_diag}
                for k in diag_values:
                    if k in label_feats:
                        label_feats[k] = label_feats[k] - diag_values[k].unsqueeze(-1) * label_onehot
                        assert torch.all(label_feats[k] > -1e-6)
                        print(k, torch.sum(label_feats[k] < 0), label_feats[k].min())

                condition = lambda ra,rb,rc,k: True
                check_acc(label_feats, condition, init_labels, train_nid, val_nid, test_nid)

                label_emb = label_feats['mmmmmmmmm']
                # label_emb = (label_feats['m'] + label_feats['mm'] + label_feats['mmm']) / 3
                check_acc({'label_emb': label_emb}, condition, init_labels, train_nid, val_nid, test_nid)

            elif args.dataset in ['ogbn-arxiv', 'ogbn-papers100M']: # single-node-type & double-edge-types
                g.ndata[tgt_type] = label_onehot

                for hop in range(1, args.num_hops + 1):
                    for k in list(g.ndata.keys()):
                        if len(k) == hop:
                            g['cite'].update_all(
                                fn.copy_u(k, 'msg'),
                                fn.mean('msg', f'm{k}'), etype='cite')
                            g['cited_by'].update_all(
                                fn.copy_u(k, 'msg'),
                                fn.mean('msg', f't{k}'), etype='cited_by')

                keys = list(g.ndata.keys())
                print(f'Involved label keys {keys}')
                for k in keys:
                    if k == tgt_type: continue
                    label_feats[k[:-1]] = g.ndata.pop(k)
                g = clear_hg(g, echo=False)

                condition = lambda ra,rb,rc,k: True
                check_acc(label_feats, condition, init_labels, train_nid, val_nid, test_nid)

                # remove self effect on label feats
                mm_diag, mt_diag, tm_diag, tt_diag = torch.load(f'{args.dataset}_diag.pt')
                diag_values = {'mm': mm_diag, 'mt': mt_diag, 'tm': tm_diag, 'tt': tt_diag}
                for k in diag_values:
                    if k in label_feats:
                        label_feats[k] = label_feats[k] - diag_values[k].unsqueeze(-1) * label_onehot
                        assert torch.all(label_feats[k] > -1e-6)
                        print(k, torch.sum(label_feats[k] < 0), label_feats[k].min())

                condition = lambda ra,rb,rc,k: True
                check_acc(label_feats, condition, init_labels, train_nid, val_nid, test_nid)

                label_emb = (label_feats['t'] + label_feats['tm'] + label_feats['mt'] + label_feats['tt']) / 4
                check_acc({'label_emb': label_emb}, condition, init_labels, train_nid, val_nid, test_nid)

            elif args.dataset == 'ogbn-mag':
                g.nodes['P'].data['P'] = label_onehot

                extra_metapath = [] # ['PAIAP']
                extra_metapath = [ele for ele in extra_metapath if len(ele) > args.num_label_hops + 1]

                if len(extra_metapath):
                    max_hops = max(args.num_label_hops + 1, max([len(ele) for ele in extra_metapath]))
                else:
                    max_hops = args.num_label_hops + 1

                g = hg_propagate(g, tgt_type, args.num_label_hops, max_hops, extra_metapath, args.mode, f_log, echo=args.debug)
 
                keys = list(g.nodes[tgt_type].data.keys())
                print(f'Involved label keys {keys}')
                f_log.write(f'Involved label keys {keys}\n')
                f_log.flush()
                for k in keys:
                    if k == tgt_type: continue
                    label_feats[k] = g.nodes[tgt_type].data.pop(k) # 이게 왜 pop이지?
                g = clear_hg(g, echo=args.debug)

                # label_feats = remove_self_effect_on_label_feats(label_feats, label_onehot)
                for k in ['PPP', 'PAP', 'PFP', 'PPPP', 'PAPP', 'PPAP', 'PFPP', 'PPFP']:
                    if k in label_feats:
                        print(f"k : {k}")

                        if args.mode=='mono' and k=='PPP':
                            diag = torch.load(f'{args.root}subgraph/{args.dataset}_P<P<P_diag.pt')
                        elif args.mode=='toggle' and k=='PPP':
                            diag = torch.load(f'{args.root}subgraph/{args.dataset}_P<PP_diag.pt')
                        else:
                            diag = torch.load(f'{args.root}subgraph/{args.dataset}_{k}_diag.pt')
                            
                        label_feats[k] = label_feats[k] - diag.unsqueeze(-1) * label_onehot

                        assert torch.all(label_feats[k] > -1e-6)
                        print(k, torch.sum(label_feats[k] < 0), label_feats[k].min())

                condition = lambda ra,rb,rc,k: True
                check_acc(label_feats, condition, init_labels, train_nid, val_nid, test_nid)

                label_emb = (label_feats['PPP'] + label_feats['PAP'] + label_feats['PP'] + label_feats['PFP']) / 4
                check_acc({'label_emb': label_emb}, condition, init_labels, train_nid, val_nid, test_nid)
        else:
            label_emb = torch.zeros((num_nodes, n_classes))

        label_feats = {k: v[init2sort] for k, v in label_feats.items()}
        label_emb = label_emb[init2sort]

        if stage == 0:
            label_feats = {}

        # =======
        # Eval loader
        # =======
        if stage > 0:
            del eval_loader
        eval_loader = []
        for batch_idx in range((num_nodes-trainval_point-1) // args.batch_size + 1):
            batch_start = batch_idx * args.batch_size + trainval_point
            batch_end = min(num_nodes, (batch_idx+1) * args.batch_size + trainval_point)

            batch_feats = {k: v[batch_start:batch_end] for k,v in feats.items()}
            batch_label_feats = {k: v[batch_start:batch_end] for k,v in label_feats.items()}
            batch_labels_emb = label_emb[batch_start:batch_end]
            eval_loader.append((batch_feats, batch_label_feats, batch_labels_emb))

        data_size = {k: v.size(-1) for k, v in feats.items()}

        # =======
        # Construct network
        # =======
        model = SeHGNN_mag(args.dataset,
            data_size, args.embed_size,
            args.hidden, n_classes,
            len(feats), len(label_feats), tgt_type,
            dropout=args.dropout,
            input_drop=args.input_drop,
            att_drop=args.att_drop,
            label_drop=args.label_drop,
            n_layers_1=args.n_layers_1,
            n_layers_2=args.n_layers_2,
            n_layers_3=args.n_layers_3,
            act=args.act,
            residual=args.residual,
            bns=args.bns, label_bns=args.label_bns,
            # label_residual=stage > 0,
            )
        model = model.to(device)
        if stage == args.start_stage:
            print(model)
            f_log.write(str(model)+'\n')

            print("# Params:", get_n_params(model))
            f_log.write(f"# Params: {get_n_params(model)}\n")
            f_log.flush()
        loss_fcn = nn.CrossEntropyLoss()
        optimizer = torch.optim.Adam(model.parameters(), lr=args.lr,
                                    weight_decay=args.weight_decay)

        best_epoch = 0
        best_val_acc = 0
        best_test_acc = 0
        count = 0

        for epoch in range(epochs):
            gc.collect()
            torch.cuda.empty_cache()
            start = time.time()
            if stage == 0:
                loss, acc = train(model, train_loader, loss_fcn, optimizer, evaluator, device, feats, label_feats, labels_cuda, label_emb, scalar=scalar)
            else:
                loss, acc = train_multi_stage(model, train_loader, enhance_loader, loss_fcn, optimizer, evaluator, device, feats, label_feats, labels_cuda, label_emb, predict_prob, args.gama, scalar=scalar)
            end = time.time()

            log = "Stage {}, Epoch {}, Time(s): {:.4f}, estimated train loss {:.4f}, acc {:.4f}\n".format(stage, epoch, end-start, loss, acc*100)
            torch.cuda.empty_cache()

            if epoch % args.eval_every == 0:
                with torch.no_grad():
                    model.eval()
                    raw_preds = []

                    start = time.time()
                    for batch_feats, batch_label_feats, batch_labels_emb in eval_loader:
                        batch_feats = {k: v.to(device) for k,v in batch_feats.items()}
                        batch_label_feats = {k: v.to(device) for k,v in batch_label_feats.items()}
                        batch_labels_emb = batch_labels_emb.to(device)
                        raw_preds.append(model(batch_feats, batch_label_feats, batch_labels_emb).cpu())
                    raw_preds = torch.cat(raw_preds, dim=0)

                    loss_val = loss_fcn(raw_preds[:valid_node_nums], labels[trainval_point:valtest_point]).item()
                    loss_test = loss_fcn(raw_preds[valid_node_nums:valid_node_nums+test_node_nums], labels[valtest_point:total_num_nodes]).item()

                    preds = raw_preds.argmax(dim=-1)
                    val_acc = evaluator(preds[:valid_node_nums], labels[trainval_point:valtest_point])
                    test_acc = evaluator(preds[valid_node_nums:valid_node_nums+test_node_nums], labels[valtest_point:total_num_nodes])

                    end = time.time()
                    log += f'Time: {end-start}, Val loss: {loss_val}, Test loss: {loss_test}\n'
                    log += 'Val acc: {:.4f}, Test acc: {:.4f}\n'.format(val_acc*100, test_acc*100)

                if val_acc > best_val_acc:
                    best_epoch = epoch
                    best_val_acc = val_acc
                    best_test_acc = test_acc

                    torch.save(model.state_dict(), f'{checkpt_file}_{stage}.pkl')
                    count = 0
                else:
                    count = count + args.eval_every
                    if count >= args.patience:
                        break
                log += name + "_Best Epoch {},Val {:.4f}, Test {:.4f}".format(best_epoch, best_val_acc*100, best_test_acc*100)
            print(log, flush=True)
            f_log.write(log)
            f_log.write('\n')
            f_log.flush()

        print(name + "_Best Epoch {}, Val {:.4f}, Test {:.4f}".format(best_epoch, best_val_acc*100, best_test_acc*100))
        f_log.write(name + "_Best Epoch {}, Val {:.4f}, Test {:.4f}\n".format(best_epoch, best_val_acc*100, best_test_acc*100))
        f_log.flush()

        
        model.load_state_dict(torch.load(checkpt_file+f'_{stage}.pkl'))
        raw_preds = gen_output_torch(model, feats, label_feats, label_emb, all_loader, device)
        torch.save(raw_preds, checkpt_file+f'_{stage}.pt')


def parse_args(args=None):
    parser = argparse.ArgumentParser(description='SeHGNN')
    ## For environment costruction
    parser.add_argument("--seeds", nargs='+', type=int, default=[1],
                        help="the seed used in the training")
    parser.add_argument("--dataset", type=str, default="ogbn-mag")
    parser.add_argument("--gpu", type=int, default=0)
    parser.add_argument("--cpu", action='store_true', default=False)
    parser.add_argument("--root", type=str, default='../data/')
    #parser.add_argument("--root", type=str, default="~/Adaptive_Sampling/dataset")
    parser.add_argument("--stages", nargs='+',type=int, default=[300, 300, 300, 300, 300],
                        help="The epoch setting for each stage.")
    ## For pre-processing
    parser.add_argument("--emb_path", type=str, default='../data/')
    parser.add_argument("--extra-embedding", type=str, default='',
                        help="the name of extra embeddings")
    parser.add_argument("--embed-size", type=int, default=256,
                        help="inital embedding size of nodes with no attributes")
    parser.add_argument("--num-hops", type=int, default=2,
                        help="number of hops for propagation of raw labels")
    parser.add_argument("--label-feats", action='store_true', default=False,
                        help="whether to use the label propagated features")
    parser.add_argument("--num-label-hops", type=int, default=2,
                        help="number of hops for propagation of raw features")
    ## For network structure
    parser.add_argument("--hidden", type=int, default=512)
    parser.add_argument("--dropout", type=float, default=0.5,
                        help="dropout on activation")
    parser.add_argument("--n-layers-1", type=int, default=2,
                        help="number of layers of feature projection")
    parser.add_argument("--n-layers-2", type=int, default=2,
                        help="number of layers of the downstream task")
    parser.add_argument("--n-layers-3", type=int, default=4,
                        help="number of layers of residual label connection")
    parser.add_argument("--input-drop", type=float, default=0.1,
                        help="input dropout of input features")
    parser.add_argument("--att-drop", type=float, default=0.,
                        help="attention dropout of model")
    parser.add_argument("--label-drop", type=float, default=0.,
                        help="label feature dropout of model")
    parser.add_argument("--residual", action='store_true', default=False,
                        help="whether to connect the input features")
    parser.add_argument("--act", type=str, default='relu',
                        help="the activation function of the model")
    parser.add_argument("--bns", action='store_true', default=False,
                        help="whether to process the input features")
    parser.add_argument("--label-bns", action='store_true', default=False,
                        help="whether to process the input label features")
    ## for training
    parser.add_argument("--amp", action='store_true', default=False,
                        help="whether to amp to accelerate training with float16(half) calculation")
    parser.add_argument("--lr", type=float, default=0.001)
    parser.add_argument("--weight-decay", type=float, default=0)
    parser.add_argument("--eval-every", type=int, default=1)
    parser.add_argument("--batch-size", type=int, default=10000)
    parser.add_argument("--patience", type=int, default=100,
                        help="early stop of times of the experiment")
    parser.add_argument("--threshold", type=float, default=0.75,
                        help="the threshold of multi-stage learning, confident nodes "
                           + "whose score above this threshold would be added into the training set")
    parser.add_argument("--gama", type=float, default=0.5,
                        help="parameter for the KL loss")
    parser.add_argument("--start-stage", type=int, default=0)
    parser.add_argument("--reload", type=str, default='')
    parser.add_argument("--name", type=str, default=None)
    parser.add_argument("--debug", action='store_true')
    parser.add_argument("--mode", type=str, default='toggle', choices=['full', 'mono', 'toggle'])
    parser.add_argument("--time-bit", type=int, default=0)
    parser.add_argument("--messi", action = 'store_true')
    parser.add_argument("--messi2017", action = 'store_true')

    return parser.parse_args(args)

'''
python new_main.py --extra-embedding complex --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 1 --name model4 --mode mono --debug

221231
python new_main.py --extra-embedding complex --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 1 --name model4 --mode mono
python new_main.py --extra-embedding complex --num-hops 2 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.001 --weight-decay 0 --threshold 0.75 --patience 100 --gama 10 --amp --seeds 1 --name model0 --mode full
python new_main.py --extra-embedding complex --hidden 584 --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 1 --name model9 --mode mono
python new_main.py --extra-embedding complex --hidden 472 --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.001 --weight-decay 0 --threshold 0.75 --patience 100 --gama 5 --amp --seeds 1 --name model10 --mode mono
python new_main.py --extra-embedding complex --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 1 --name model4_womessi --mode mono

230101
python new_main.py --extra-embedding complex --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 1 --eval-every 10 --name model4_stage10 --mode mono 
python new_main.py --extra-embedding complex --hidden 640 --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0006 --weight-decay 0 --threshold 0.7 --patience 100 --gama 5 --amp --seeds 1 --name model11 --mode mono
python new_main.py --extra-embedding complex --time-bit 20 --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 1 --name model4_time --mode mono
python new_main.py --extra-embedding complex --hidden 400 --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0012 --weight-decay 0 --threshold 0.75 --patience 100 --gama 5 --amp --seeds 1 --name model12 --mode mono


python new_main.py --stages 200 200 200 200 200 200 --extra-embedding complex --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 1 --name model4_short --mode mono
python new_main.py --stages 150 150 150 150 150 150 --extra-embedding complex --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 1 --name model4_little --mode mono
python new_main.py --stages 200 200 200 200 200 200 --extra-embedding complex --hidden 400 --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0012 --weight-decay 0 --threshold 0.75 --patience 100 --gama 5 --amp --seeds 1 --name model12_short --mode mono
python new_main.py --stages 120 120 120 120 120 120 --extra-embedding complex --hidden 460 --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.001 --weight-decay 0 --threshold 0.75 --patience 100 --gama 5 --amp --seeds 1 --name model13_short --mode mono
python new_main.py --stages 90 90 90 90 90 90 --extra-embedding complex --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 1 --name model4_mini --mode mono

python new_main.py --stages 100 100 100 100 100 100 --extra-embedding complex --hidden 400 --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0012 --weight-decay 0 --threshold 0.75 --patience 100 --gama 5 --amp --seeds 1 --name model12_short --mode mono

python new_main.py --extra-embedding complex --hidden 460 --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0012 --weight-decay 0 --threshold 0.75 --patience 100 --gama 5 --amp --seeds 1 --name model13 --mode mono
python new_main.py --extra-embedding complex --hidden 320 --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0012 --weight-decay 0 --threshold 0.75 --patience 100 --gama 5 --amp --seeds 1 --name model14 --mode mono


230102
python new_main.py --stages 200 200 300 300 300 --extra-embedding complex --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 1 --name model4_stage1 --mode mono
python new_main.py --stages 150 150 300 300 300 --extra-embedding complex --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 1 --name model4_stage2 --mode mono
python new_main.py --stages 120 120 300 300 300 --extra-embedding complex --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 1 --name model4_stage3 --mode mono
python new_main.py --stages 250 250 300 300 300 --extra-embedding complex --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 1 --name model4_stage4 --mode mono
python new_main.py --stages 400 400 300 300 300 --extra-embedding complex --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 1 --name model4_stage5 --mode mono

230111
python new_main.py --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 1 --name model4_seed1 --mode mono
python new_main.py --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 2 --name model4_seed2 --mode mono

230111
python new_main.py --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 1 --name model4_seed1 --mode mono
python new_main.py --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 2 --name model4_seed2 --mode mono

python new_main.py --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 20 --name model4_seed20 --mode mono
python new_main.py --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 3 --name model4_seed3 --mode mono
python new_main.py --messi2017 --num-hops 3 --label-feats --num-label-hops 2 --n-layers-1 2 --n-layers-2 2 --residual --act leaky_relu --bns --label-bns --lr 0.0008 --weight-decay 0 --threshold 0.8 --patience 100 --gama 5 --amp --seeds 4 --name model4_seed4 --mode mono
'''


if __name__ == '__main__':
    args = parse_args()
    assert args.dataset.startswith('ogbn')
    assert args.name!=None

    print(args)

    for seed in args.seeds:
        args.seed = seed
        print('Restart with seed =', seed)
        main(args)
