#!/bin/bash

# Define the input .dat file; we can add more file
input_file1="/eos/home-q/qunguyen/highland_3.11_output/numuCCOuterDetector_V12/MC/data_split_00011000/run_period_9_list.dat"
input_file2="/eos/home-q/qunguyen/highland_3.11_output/numuCCOuterDetector_V12/MC/data_split_00011000/run_period_10_list.dat"
input_file2="/eos/home-q/qunguyen/highland_3.11_output/numuCCOuterDetector_V12/MC/data_split_00011000/run_period_11_list.dat"
input_file2="/eos/home-q/qunguyen/highland_3.11_output/numuCCOuterDetector_V12/MC/data_split_00011000/run_period_12_list.dat"


# Define the output merged file
output_file="/eos/home-q/qunguyen/highland_3.11_output/numuCCOuterDetector_V12/MC/merge_file/run6_air_RHC_period_9_10_11_12.root"

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

# Merge files from the .dat files
merge_files_from_list "$input_file1" "$output_file"
merge_files_from_list "$input_file2" "$output_file"
merge_files_from_list "$input_file3" "$output_file"
merge_files_from_list "$input_file4" "$output_file"
