#include <TH1D.h>
#include <TString.h>
#include <vector>
#include <map>
using namespace std;
void cc4piMultiPiNumu(){

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

    const char * sample_names[12] = {"Fwd_CC0Pi0p","Fwd_CC0PiNp","Bwd_CC0Pi0p","Bwd_CC0PiNp","HAFwd_CC0Pi0p","HAFwd_CC0PiNp","HABwd_CC0Pi0p","HABwd_CC0PiNp","Fwd_CC1Pi","HAFwd_CC1Pi","Fwd_CCOther","CCPhoton"};
    const char * accum_levels[12] = {   "[0]>8"   ,   "[1]>8"   ,   "[2]>8"   ,   "[3]>8"   ,    "[4]>8"    ,    "[5]>8"    ,   "[6]>8"   ,   "[7]>8"   ,  "[8]>7"  ,   "[9]>7"   ,   "[10]>7"  , "[11]>6" };

    int i_sample=11;    

    TString package = "numuFHC";

    TString FGD = "FGD1";
    // TString FGD = "FGD2";

    // TString variable = "costheta";
    TString variable = "pmu";
    // TString path_to_input = "/eos/home-q/qunguyen/highland_3.4.1_output/numuCC4piMultiPiAnalysis/prod7_V12_neut_D_2015-08-water_magnet_run8_accum2/";
    TString path_to_input = "";
 
    std::map<TString, TString> input_file;
 
    // input_file["numuFHC"]="merge_run8_water.root";
    input_file["numuFHC"]="test_4pi.root";
    
    // input_file["anumuRHC"]="antiNumuCCMultiPi_accum2_test.root";
    // input_file["numuBkgRHC"]="numuBkgInAntiNu_1core.root";

//     std::map<TString, TString> input_file = {
//     {"numuBkgRHC", "hl2_accum_cut_2_output_numuBkgInAntiNuMode.root"},
//     {"numuFHC", "hl2_accum_cut_2_output_numuCCmultiPiAnalysis.root"},
//     {"anumuRHC", "hl2_accum_cut_2_output_AntiNumuCCAnalysis.root"},
// };

     char full_file_name[256];
    // sprintf(full_file_name,"/sps/t2k/quocviet/data/final_merge_dir/%s",input_file[package].Data());

    sprintf(full_file_name,"%s%s",path_to_input.Data(),input_file[package].Data());

    //Initialises DrawingTools with a random .root file
    DrawingTools draw(full_file_name);
    Experiment exp("nd280");

    cout<< input_file[package] <<endl;
    
    DataSample* mc = new DataSample(full_file_name);
    
    // DataSample* mc = new DataSample(Form("/sps/t2k/quocviet/data/final_merge_dir/%s",input_file[package]));
   
    SampleGroup run8("run8");
    run8.AddMCSample("magnet",mc);  
    exp.AddSampleGroup("run8",run8);  


    //CC0pi
    string accum_level_fgd1 = "[][0]>6";
    string accum_level_fgd2 = "[0][1][0]>6";
    string mode = "CC0pi";
    //CC0pi,  numuBkginRHC
    // string accum_level_fgd1 = "[][0]>7";
    // string accum_level_fgd2 = "[0][1][0]>7";
    // string mode = "CC0pi";

    //CC inclusive numu FHC
    // string accum_level_fgd1 = "[][]>5";
    // string accum_level_fgd2 = "[][1][]>5";
    // string mode = "CC inclusive";

     //CC inclusive anti-numu RHC, numuBkginRHC
    // string accum_level_fgd1 = "[][]>6";
    // string accum_level_fgd2 = "[][1][]>6";
    // string mode = "CC inclusive";
    // if(package == "numuBkgRHC"){
        //FGD1*********************************************************
         TCanvas *c1 = new TCanvas("c1","c1", 800,600);
        draw.SetTitle(Form("%s ",sample_names[i_sample]));
        draw.SetTitleX("p_#mu MeV");
        // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level"+accum_level_fgd1+" &&"+sel.Data(),"","pur");
        draw.Draw(exp, "selmu_mom", 50, 0, 6000, "reaction", Form("accum_level[0]%s",accum_levels[i_sample]),"","pur");
        // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd_numu_oofv", "accum_level[][0]>5 && topology==7","","pur");
      
        TH1D* h1_test = (TH1D*)draw.GetLastStackTotal();
        double entries_h1=h1_test->GetEntries();
        c1->Print(Form("../plotPDFs/cc4pi/%s.pdf",sample_names[i_sample]));
    
        // TCanvas *c2 = new TCanvas("c2","c2", 800,600);
        // draw.SetTitle(Form("%s %s sample",mode.c_str(),package.Data()));
        // draw.SetTitleX("p_#mu MeV");
        // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level"+accum_level_fgd1+" && !"+sel_true_FV_FGD1+"&&"+sel_reco_FV_FGD1);
        // TH1D* h2_test = (TH1D*)draw.GetLastStackTotal();
        // double entries_h2=h2_test->GetEntries();
        // double rate=entries_h2/entries_h1;
        // cout<<"ratefgd1: "<<rate<<endl;
        //FGD2**********************************************************
        // TCanvas *c3 = new TCanvas("c3","c3", 800,600);
        // draw.SetTitle(Form("%s %s sample",mode.c_str(),package.Data()));
        // draw.SetTitleX("p#_#mu MeV");
        // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level"+accum_level_fgd2+" &&"+sel_reco_FGD1_HA,"","pur");
        // // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level"+accum_level_fgd2);
        // h1_test = (TH1D*)draw.GetLastStackTotal();
        // entries_h1=h1_test->GetEntries();
        
        // TCanvas *c4 = new TCanvas("c4","c4", 800,600);
        // draw.SetTitle(Form("%s %s sample",mode.c_str(),package.Data()));
        // draw.SetTitleX("p_#mu MeV");
        // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level"+accum_level_fgd2+" && !"+sel_true_FV_FGD2+"&&"+sel_reco_FV_FGD2);
        // h2_test = (TH1D*)draw.GetLastStackTotal();
        // entries_h2=h2_test->GetEntries();
        // rate=entries_h2/entries_h1;
        // cout<<"ratefgd2: "<<rate<<endl;
        
    // }

}   