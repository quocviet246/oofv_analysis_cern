#!/bin/bash
source /sps/t2k/quocviet/highlandsw/highland_prod7_V12_3.4.1/nd280SoftwarePilot/nd280SoftwarePilot.profile
source /sps/t2k/quocviet/highlandsw/highland_prod7_V12_3.4.1/highland2SoftwarePilot/highland2SoftwarePilot.profile
source /sps/t2k/quocviet/highlandsw/highland_prod7_V12_3.4.1/highland2Master_3.4.1/bin/setup.sh
#the package below is not in the main highland2 Master so I source it here
source /sps/t2k/quocviet/highlandsw/highland_prod7_V12_3.4.1/numuCCOuterDetAnalysis/bin/setup.sh

export LD_LIBRARY_PATH=/pbs/throng/t2k/gl2ps/install/lib:$LD_LIBRARY_PATH

# source numuCCAnalysis_2.22/bin/setup.sh
# source numuCCMultiPiAnalysis_2.32/bin/setup.sh

# RunNumuCCMultiPiAnalysis.exe -o test1.root ../hl2input/oa_nt_beam_90400000-0038_qxxasyulf6tr_anal_000_magnet201011airrun4-bsdv01_2.root &
# RunNumuCCMultiPiAnalysis.exe -o test3.root ../hl2input/oa_nt_beam_90400000-0038_qxxasyulf6tr_anal_000_magnet201011airrun4-bsdv01_2.root
