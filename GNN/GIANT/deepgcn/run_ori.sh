python ./main_modify.py --data_root_dir ../dataset \
--pretrain_path ../proc_data_xrt/ogbn-arxiv/X.all.xrt-emb.npy \
--seed 1 --n-runs 1 --use-norm --use-labels --n-label-iters=1 --no-attn-dst --edge-drop=0.3 --input-drop=0.25 --n-layers 2 --dropout 0.75 --n-hidden 256 --backbone rev --group 2 --mode teacher --seed 0\
|& tee modified_ori/teacher_res_giant-xrt1.log

python ./main_modify.py --data_root_dir ../dataset \
--pretrain_path ../proc_data_xrt/ogbn-arxiv/X.all.xrt-emb.npy \
--seed 2 --n-runs 1 --use-norm --use-labels --n-label-iters=1 --no-attn-dst --edge-drop=0.3 --input-drop=0.25 --n-layers 2 --dropout 0.75 --n-hidden 256 --backbone rev --group 2 --mode teacher --seed 0\
|& tee modified_ori/teacher_res_giant-xrt2.log

python ./main_modify.py --data_root_dir ../dataset \
--pretrain_path ../proc_data_xrt/ogbn-arxiv/X.all.xrt-emb.npy \
--seed 3 --n-runs 1 --use-norm --use-labels --n-label-iters=1 --no-attn-dst --edge-drop=0.3 --input-drop=0.25 --n-layers 2 --dropout 0.75 --n-hidden 256 --backbone rev --group 2 --mode teacher --seed 0\
|& tee modified_ori/teacher_res_giant-xrt3.log

python ./main_modify.py --data_root_dir ../dataset \
--pretrain_path ../proc_data_xrt/ogbn-arxiv/X.all.xrt-emb.npy \
--seed 4 --n-runs 1 --use-norm --use-labels --n-label-iters=1 --no-attn-dst --edge-drop=0.3 --input-drop=0.25 --n-layers 2 --dropout 0.75 --n-hidden 256 --backbone rev --group 2 --mode teacher --seed 0\
|& tee modified_ori/teacher_res_giant-xrt4.log

python ./main_modify.py --data_root_dir ../dataset \
--pretrain_path ../proc_data_xrt/ogbn-arxiv/X.all.xrt-emb.npy \
--seed 5 --n-runs 1 --use-norm --use-labels --n-label-iters=1 --no-attn-dst --edge-drop=0.3 --input-drop=0.25 --n-layers 2 --dropout 0.75 --n-hidden 256 --backbone rev --group 2 --mode teacher --seed 0\
|& tee modified_ori/teacher_res_giant-xrt5.log

python ./main_modify.py --data_root_dir ../dataset \
--pretrain_path ../proc_data_xrt/ogbn-arxiv/X.all.xrt-emb.npy \
--seed 6 --n-runs 1 --use-norm --use-labels --n-label-iters=1 --no-attn-dst --edge-drop=0.3 --input-drop=0.25 --n-layers 2 --dropout 0.75 --n-hidden 256 --backbone rev --group 2 --mode teacher --seed 0\
|& tee modified_ori/teacher_res_giant-xrt6.log

python ./main_modify.py --data_root_dir ../dataset \
--pretrain_path ../proc_data_xrt/ogbn-arxiv/X.all.xrt-emb.npy \
--seed 7 --n-runs 1 --use-norm --use-labels --n-label-iters=1 --no-attn-dst --edge-drop=0.3 --input-drop=0.25 --n-layers 2 --dropout 0.75 --n-hidden 256 --backbone rev --group 2 --mode teacher --seed 0\
|& tee modified_ori/teacher_res_giant-xrt7.log

python ./main_modify.py --data_root_dir ../dataset \
--pretrain_path ../proc_data_xrt/ogbn-arxiv/X.all.xrt-emb.npy \
--seed 8 --n-runs 1 --use-norm --use-labels --n-label-iters=1 --no-attn-dst --edge-drop=0.3 --input-drop=0.25 --n-layers 2 --dropout 0.75 --n-hidden 256 --backbone rev --group 2 --mode teacher --seed 0\
|& tee modified_ori/teacher_res_giant-xrt8.log

