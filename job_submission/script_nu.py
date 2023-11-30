import os
import multiprocessing

# Set the directory path where your files are located

#Run8 FHC MC
input_directory_path = '/sps/t2k/quocviet/data/hl2_input/prod7_V12_neut_D_2015-08-water_magnet_run8/'
#Run4 FHC MC
# input_directory_path = '/sps/t2k/quocviet/data/hl2_input/prod7_V12_neut_D_2010-11-air_magnet_run4/'

#Data
# input_directory_path = '/sps/t2k/quocviet/data/hl2_input/data_nd280_prod7_v13/00011000_00011999/anal/'


# Runpackage = 'RunNumuCCOuterDetAnalysis.exe'
# output_directory_path = '/sps/t2k/quocviet/data/hl2_3.4.1_output/numuCCOuterDetAnalysis/data_parallel/00011000_00011999/'

# Runpackage = 'RunNumuCCOuterDetAnalysis.exe'
# output_directory_path = '/sps/t2k/quocviet/data/hl2_3.4.1_output/numuCCOuterDetAnalysis/MC/prod7_V12_neut_D_2010-11-air_magnet_run4/'


# Runpackage = 'RunNumuCCMultiPiAnalysis.exe'
# output_directory_path = '/sps/t2k/quocviet/data/hl2_3.4.1_output/numuCCMultiPi_accum2/parallel_run/'


Runpackage = 'RunNumuCC4piMultiPiAnalysis.exe'
output_directory_path = '/sps/t2k/quocviet/data/hl2_3.4.1_output/numuCC4piMultiPiAnalysis/prod7_V12_neut_D_2015-08-water_magnet_run8_accum2/parallel/'

# Runpackage = 'RunNumuCC4piMultiPiAnalysis.exe'
# output_directory_path = '/sps/t2k/quocviet/data/hl2_3.7_output/numuCC4PIMulitiPi/parallel'

# Runpackage = 'RunNumuCCAnalysis.exe'
# output_directory_path = '/sps/t2k/quocviet/data/hl2_3.4.1_output/numuCCAnalysis_accum2/parallel_run/'


# Define the number of cores to use
num_cores = 20

# Define a function to run the executable on a file
def run_executable(file_name):
    print(file_name)
    # Create the command to run the executable with the file as input
    command = Runpackage+ ' -o '+output_directory_path + str(file_name)+ ' '+    input_directory_path+str(file_name)
    # Run the command
    os.system(command)


# Create a list of file names in the directory and sort them alphabetically
# file_list = sorted(os.listdir(input_directory_path))
# file_list = sorted(os.listdir(input_directory_path))[:10]  # Include only the first 100 files
file_list = sorted(os.listdir(input_directory_path)) # Include all files

# Create a pool of workers
pool = multiprocessing.Pool(num_cores)

# Run the function on each file in parallel using the pool of workers
pool.map(run_executable, file_list)

# Close the pool of workers
pool.close()

# Wait for the pool of workers to finish
pool.join()
