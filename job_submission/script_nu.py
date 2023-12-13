import os
import multiprocessing

# Set the directory path where your files are located
# data_general_path = '/eos/experiment/neutplatform/t2knd280/ND280AnalysisFiles/nd280/oaanalysis/data/production7/'

#Run6 RHC MC
data_general_path = '/eos/experiment/neutplatform/t2knd280/ND280AnalysisFiles/nd280/oaanalysis/neut/production7/V12/anti_nu/run6air/'
input_directory_path = data_general_path #+ 'V12/unsorted/00012000_00012999/'
# input_directory_path = data_general_path+ 'run6e_air_RHC/'

# Runpackage = 'RunNumuCCOuterDetAnalysis.exe'
Runpackage = 'RunAntiNumuCCAnalysis.exe'
# Runpackage = 'RunNumuCCMultiPiAnalysis.exe'
# Runpackage = 'RunNumuCC4piMultiPiAnalysis.exe'


# output_directory_path = '/eos/home-q/qunguyen/highland_3.11_output/numuCCOuterDetector_V12/MC_update/run6air_RHC/'

output_directory_path = '/eos/home-q/qunguyen/highland_3.11_output/antiNumuCCAnalysis/run6air/'

# output_directory_path = '/eos/home-q/qunguyen/highland_3.11_output/numuCCOuterDetector_V12/data/run6bcde_air_RHC/'
# Define the number of cores to use
num_cores = 20

# Define a function to run the executable on a file
def run_executable(file_name):
    print(file_name)
    # Create the command to run the executable with the file as input
    command = Runpackage+ ' -v -o '+output_directory_path + str(file_name)+ ' '+    input_directory_path+str(file_name)
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
