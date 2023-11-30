#!/bin/bash

# Define the input .dat file; we can add more file
input_file1="/sps/t2k/quocviet/data/hl2_3.4.1_output/numuCCOuterDetAnalysis/data_parallel/file_list_12/run_period_17_list.dat"
input_file2="/sps/t2k/quocviet/data/hl2_3.4.1_output/numuCCOuterDetAnalysis/data_parallel/file_list_13/run_period_17_list.dat"


# Define the output merged file
output_file="/sps/t2k/quocviet/data/hl2_3.4.1_output/numuCCOuterDetAnalysis/data_parallel/final_merge_output/run8_water_FHC_period17.root"

# Function to merge files from a list
function merge_files_from_list {
  local list_file="$1"
  local merged_file="$2"
  
  if [ ! -f "$list_file" ]; then
    echo "Input file '$list_file' does not exist."
    return
  fi
  
  # Read the list of files from the input .dat file and store them in an array
  readarray -t files < "$list_file"
  
  if [ ${#files[@]} -eq 0 ]; then
    echo "No files to merge from '$list_file'."
    return
  fi
  
  # Use hadd to merge the files
  hadd -f "$merged_file" "${files[@]}"
  
  if [ $? -eq 0 ]; then
    echo "Merging from '$list_file' completed. Merged file: $merged_file"
  else
    echo "Error occurred while merging files from '$list_file'."
  fi
}

# Merge files from the first .dat file
merge_files_from_list "$input_file1" "$output_file"

# Merge files from the second .dat file
merge_files_from_list "$input_file2" "$output_file"
