#!/bin/bash
#SBATCH --job-name=myjob
#SBATCH --ntasks=1
#SBATCH --mem=16G
#SBATCH --time=1:00:00
#SBATCH --output=output.log

# Load required modules
module load root

# Change to the directory containing your ROOT macro and input files
cd /sps/t2k/quocviet/highland2/Viet_macros

# Run the ROOT macro
root -l -b -q MergeRootFiles.C 

# Exit
exit 0 