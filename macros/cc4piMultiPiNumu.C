#include <TH1D.h>
#include <TString.h>
#include <vector>
#include <map>
// #include <stdlib.h>
using namespace std;

void cc4piMultiPiNumu(){
    //highland selection
    const char * sample_names[12] = {"Fwd_CC0Pi0p","Fwd_CC0PiNp","Bwd_CC0Pi0p","Bwd_CC0PiNp","HAFwd_CC0Pi0p","HAFwd_CC0PiNp","HABwd_CC0Pi0p","HABwd_CC0PiNp","Fwd_CC1Pi","HAFwd_CC1Pi","Fwd_CCOther","CCPhoton"};
    const char * accum_levels[12] = {   "[0]>8"   ,   "[1]>8"   ,   "[2]>8"   ,   "[3]>8"   ,    "[4]>8"    ,    "[5]>8"    ,   "[6]>8"   ,   "[7]>8"   ,  "[8]>7"  ,   "[9]>7"   ,   "[10]>7"  , "[11]>6" };

    TString FGD = "FGD1";
    // TString FGD = "FGD2";

    // TString variable = "costheta";
    TString variable = "pmu";

    // system("/afs/cern.ch/work/q/qunguyen/public/oofv_analysis_cern/setup/highland2_V12_3.7_setup.sh");
    TString path_to_input = "/eos/home-q/qunguyen/highland_3.7_V12_output/numuCC4PiMultiPi/";
    TString input_file="merge_run48_FHC.root";
    
//    system("/afs/cern.ch/work/q/qunguyen/public/oofv_analysis_cern/setup/highland2_V7E_3.12_setup.sh");
   
    // TString path_to_input = "/eos/home-q/qunguyen/highland_3.12_V7E_output/numuCC4PiMultiPi/";
    // TString input_file="merge_run4air.root";
    // TString input_file1="merge_run4water.root";
    

    char full_file_name[256];
    sprintf(full_file_name,"%s%s",path_to_input.Data(),input_file.Data());

    char full_file_name1[256];
    // sprintf(full_file_name1,"%s%s",path_to_input.Data(),input_file1.Data());

    //Initialises DrawingTools with a random .root file
    DrawingTools draw(full_file_name);
    Experiment exp("nd280");

    cout<< input_file <<endl;
    
    DataSample* mc = new DataSample(full_file_name);
    // DataSample* mc1 = new DataSample(full_file_name1);
    
    // DataSample* mc = new DataSample(Form("/sps/t2k/quocviet/data/final_merge_dir/%s",input_file));

    SampleGroup run4air("run4air");
    run4air.AddMCSample("magnet",mc);  

    // SampleGroup run4water("run4water");
    // run4water.AddMCSample("magnet",mc1);  

    exp.AddSampleGroup("run4air",run4air);  
    // exp.AddSampleGroup("run4water",run4water);  

    const char * catagory = "detector";
    // Catagories to be used: topology, reaction, particle, OOFV, detector
    for(int i_sample=0;i_sample<12;i_sample++){
        TCanvas *c1 = new TCanvas("c1","c1", 800,600);
        draw.SetTitle(Form("%s ",sample_names[i_sample]));
        draw.SetTitleX("Reconstructed p_{#mu} [MeV/c]");
        draw.SetTitleY("Events");
        draw.SetLegendPos("tr");

        // draw.Draw(exp, "selmu_mom", 20, 0, 5000, catagory, Form("topology==7 && accum_level[0]%s",accum_levels[i_sample]),"","pur");
        draw.Draw(exp, "selmu_mom", 20, 0, 5000, catagory, Form("accum_level[0]%s",accum_levels[i_sample]),"","pur");
      
        TH1D* h1_test = (TH1D*)draw.GetLastStackTotal();
        double entries_h1=h1_test->GetEntries();
        c1->Print(Form("../plotPDFs/cc4pi_V12_37/pmu_%s_%s.pdf",catagory,sample_names[i_sample]));

    }

    // for(int i_sample=0;i_sample<12;i_sample++){
    //     TCanvas *c2 = new TCanvas("c2","c2", 800,600);
    //     draw.SetTitle(Form("%s ",sample_names[i_sample]));
    //     draw.SetTitleX("Reconstructed cos#theta_{#mu}");
    //     draw.SetTitleY("Events");
    //     TString backward_check = Form("%s",sample_names[i_sample]);
    //     if (backward_check.Contains("Bwd")) {draw.SetLegendPos("tr");}
    //     else {draw.SetLegendPos("tl");}
    //     draw.Draw(exp, "selmu_costheta", 20, -1, 1, catagory, Form("topology==7 && accum_level[0]%s",accum_levels[i_sample]),"","pur");
      
    //     TH1D* h1_test = (TH1D*)draw.GetLastStackTotal();
    //     double entries_h1=h1_test->GetEntries();
    //     c2->Print(Form("../plotPDFs/cc4pi_OOFV_V12_37/costheta_%s_%s.pdf",catagory,sample_names[i_sample]));
    
    // }

}   

void viet_selection(){
    //Viet's additional selection
    // LA stands for Low Angle, HA stands for High Angle
    string sel_reco_FGD1_LA = "(abs(selvtx_pos[0])<874.51 && selvtx_pos[1]>819.51 && selvtx_pos[1]<929.51 && selvtx_pos[2]>125.75 && selvtx_pos[2]<447.375)";
    string sel_reco_FGD1_HA = "(abs(selvtx_pos[0])<874.51 && selvtx_pos[1]>819.51 && selvtx_pos[1]<929.51 && selvtx_pos[2]>125.75 && selvtx_pos[2]<437.255)";
    string sel_reco_FGD2_LA = "(abs(selvtx_pos[0])<874.51 && selvtx_pos[1]>819.51 && selvtx_pos[1]<929.51 && selvtx_pos[2]>1483.75 && selvtx_pos[2]<1807.375)";
    string sel_reco_FGD2_HA = "(abs(selvtx_pos[0])<874.51 && selvtx_pos[1]>819.51 && selvtx_pos[1]<929.51 && selvtx_pos[2]>1483.75 && selvtx_pos[2]<1797.255)";
   

    string forward_track = "(selmu_endpos[2]-selmu_pos[2]>0)";
    string backward_track = "(selmu_endpos[2]-selmu_pos[2]<0)";


    //Selection LA: Low Angle, HA: High Angle, FWD: forward, BWW
    TString selection = "FGD1_LA_FWD"; 
    // TString selection = "FGD1_HA_FWD";
    // TString selection = "FGD1_LA_BWD";
    // TString selection = "FGD1_HA_BWD";
    TString sel = "";
    if(selection.Contains("FGD1_LA")){
        sel+=sel_reco_FGD1_LA.c_str();
    }else if (selection.Contains("FGD1_HA")){
       sel+=sel_reco_FGD1_HA.c_str();
    }
    sel+="&&";
    if(selection.Contains("FWD")){
        sel+=forward_track.c_str();
    }else if (selection.Contains("BWD")){
       sel+=backward_track.c_str();
    }
}

void input_read_highland_312_V7E(){
    TString path_to_input = "/eos/home-q/qunguyen/highland_3.7_V12_output/numuCC4PiMultiPi/";
    TString input_file="merge_run48_FHC.root";
    char full_file_name[256];
    sprintf(full_file_name,"%s%s",path_to_input.Data(),input_file.Data());
}