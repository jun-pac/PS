num_hops=6
DATA_ROOT_DIR=./dataset
output_emb_prefix=./ogbn-papers100M-pmp.node-emb
input_emb_path=None
gpu=0


python experiment_papers100m.py --root ${DATA_ROOT_DIR} --num_hops ${num_hops} --pretrained_emb_path ${input_emb_path} --jjnorm --output_emb_prefix ${output_emb_prefix} |& tee ./exp.JJ.log