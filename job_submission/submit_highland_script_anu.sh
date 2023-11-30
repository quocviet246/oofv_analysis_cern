#!/bin/sh

# SLURM options:

# SBATCH --job-name=serial_job_test    # Job name
# SBATCH --output=serial_test_%j.log   # Standard output and error log

#SBATCH --partition=htc               # Partition choice (htc by default)

# SBATCH --ntasks=2                    # Run a single task
# SBATCH --mem=2000                    # Memory in MB per default
# SBATCH --time=0-00:30:00             # Max time limit = 7 days

# SBATCH --mail-user=<qvnguyen@llr.in2p3.fr>   # Where to send mail
# SBATCH --mail-type=END,FAIL          # Mail events (NONE, BEGIN, END, FAIL, ALL)


source /sps/t2k/quocviet/oofv_analysis/highland2_V12_3.4.1_setup.sh
source /sps/t2k/quocviet/oofv_analysis/setup_for_installation.sh

# Commands to be submitted:

module load python
python script_anu.py

#command line to submit on CCLyon
#sbatch -t 0-01:20 -n 70 --mem 30G submit_script.sh
