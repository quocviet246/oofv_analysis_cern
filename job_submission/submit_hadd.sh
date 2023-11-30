#!/bin/bash
#SBATCH --job-name=hadd
#SBATCH --output=hadd_%j.out
#SBATCH --error=hadd_%j.err
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --time=01:00:00
#SBATCH --mem=30G

# Load necessary modules
module load root

# Set input directory and output file name
# inputDir=/sps/t2k/quocviet/data/hl2_accum_cut_5_output
inputDir=/sps/t2k/quocviet/data/hl2_accum_cut_2_output_AntiNumuCCAnalysis

outputFile=/sps/t2k/quocviet/data/final_merge_dir/hl2_accum_cut_2_output_AntiNumuCCAnalysis_final.root

# Run hadd command
hadd -f $outputFile $inputDir/*.root

