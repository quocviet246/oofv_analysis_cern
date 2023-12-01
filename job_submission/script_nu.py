import os
import multiprocessing

# Set the directory path where your files are located
data_general_path = '/eos/experiment/neutplatform/t2knd280/ND280AnalysisFiles/nd280/oaanalysis/data/production7/'
#Run8 FHC MC
input_directory_path = '/sps/t2k/quocviet/data/hl2_input/prod7_V12_neut_D_2015-08-water_magnet_run8/'

# Runpackage = 'RunNumuCCOuterDetAnalysis.exe'
# Runpackage = 'RunNumuCCMultiPiAnalysis.exe'
Runpackage = 'RunNumuCC4piMultiPiAnalysis.exe'


output_directory_path = '/sps/t2k/quocviet/data/hl2_3.4.1_output/numuCC4piMultiPiAnalysis/prod7_V12_neut_D_2015-08-water_magnet_run8_accum2/parallel/'

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
file_list = sorted(os.listdir(input_directory_path))[:10]  # Include only the first 100 files
# file_list = sorted(os.listdir(input_directory_path)) # Include all files

# Create a pool of workers
pool = multiprocessing.Pool(num_cores)

# Run the function on each file in parallel using the pool of workers
pool.map(run_executable, file_list)

# Close the pool of workers
pool.close()

# Wait for the pool of workers to finish
pool.join()