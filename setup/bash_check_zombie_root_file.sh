#!/bin/bash
for filename_to_check in /sps/t2k/quocviet/data/hl2_3.4.1_output/AntiNumuCCMultiPi_accum2_test/*.root
  do
    root.exe -b -l -q -e "auto f = TFile::Open(\"$filename_to_check\"); if (f == nullptr || f->IsZombie()) { cout << \"There is a problem with the file: $filename_to_check\n\"; exit(1); }"
    if [ $? -ne 0 ]; then
        echo $filename_to_check has error
        exit 1
   fi
 done ;