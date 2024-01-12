#!/bin/bash

# List of input directories
# inputDirs=("/eos/home-q/qunguyen/highland_3.11_V7E_output/numuCCOuterDetector/data/run6b_air_RHC" "/eos/home-q/qunguyen/highland_3.11_V7E_output/numuCCOuterDetector/data/run6c_air_RHC" "/eos/home-q/qunguyen/highland_3.11_V7E_output/numuCCOuterDetector/data/run6d_air_RHC" "/eos/home-q/qunguyen/highland_3.11_V7E_output/numuCCOuterDetector/data/run6e_air_RHC")
inputDirs=("/eos/home-q/qunguyen/highland_3.11_V7E_output/numuCCOuterDetector/MC/run6air_RHC")

# Output directory
# outputDir="/eos/home-q/qunguyen/highland_3.11_V7E_output/numuCCOuterDetector/data"
outputDir="/eos/home-q/qunguyen/highland_3.11_V7E_output/numuCCOuterDetector/MC"

# Output file name
outputFile="merged_MC_run6_air_RHC.root"

# Iterate over input directories
for inputDir in "${inputDirs[@]}"; do
    # Run hadd command for each input directory
    hadd -f "${outputDir}/${outputFile}" "${inputDir}"/*.root

    # If you want to keep separate output files for each input directory, you can use a different output file name
    # outputFileName=$(basename "${inputDir}")"_merged_output.root"
    # hadd -f "${outputDir}/${outputFileName}" "${inputDir}"/*.root
done