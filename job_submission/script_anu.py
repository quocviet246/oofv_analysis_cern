import os
import multiprocessing

# Set the directory path where your files are located
# directory_path = '/sps/t2k/quocviet/data/hl2input_anu_V12/'
# output_directory_path = '/sps/t2k/quocviet/data/hl2_accum_cut_2_output_AntiNumuCCAnalysis/'

directory_path = '/sps/t2k/quocviet/data/hl2_input/prod7_V12_anti-neut_D_2015-08-water_magnet_run7/'
output_directory_path = '/sps/t2k/quocviet/data/hl2_3.4.1_output/AntiNumuCCMultiPi_accum2/'

# Define the number of cores to use
num_cores = 50

# Define a function to run the executable on a file
def run_executable(file_name):
    print(file_name)
    # Create the command to run the executable with the file as input
    command = 'RunAntiNumuCCAnalysis.exe -o '+output_directory_path + str(file_name)+ ' '+    directory_path+str(file_name)
    # Run the command
    os.system(command)

# Create a list of file names in the directory
# file_list = os.listdir(directory_path)[:10]  # Include only the first 100 files
file_list = os.listdir(directory_path) # Include all files

# Create a pool of workers
pool = multiprocessing.Pool(num_cores)

# Run the function on each file in parallel using the pool of workers
pool.map(run_executable, file_list)

# Close the pool of workers
pool.close()

# Wait for the pool of workers to finish
pool.join()
ls