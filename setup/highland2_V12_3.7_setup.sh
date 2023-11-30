#!/bin/bash
source /sps/t2k/quocviet/highlandsw/highland_prod7_V12_3.7/nd280SoftwarePilot/nd280SoftwarePilot.profile
source /sps/t2k/quocviet/highlandsw/highland_prod7_V12_3.7/highland2SoftwarePilot/highland2SoftwarePilot.profile
source /sps/t2k/quocviet/highlandsw/highland_prod7_V12_3.7/highland2Master_3.7/bin/setup.sh
#the package below is not in the main highland2 Master so I source it here
# source /sps/t2k/quocviet/highlandsw/highland_prod7_V12_3.7numuCCOuterDetAnalysis/bin/setup.sh

export LD_LIBRARY_PATH=/pbs/throng/t2k/gl2ps/install/lib:$LD_LIBRARY_PATH
