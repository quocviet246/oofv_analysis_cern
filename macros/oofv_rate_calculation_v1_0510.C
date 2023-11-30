#include <TH1D.h>
#include <TString.h>
#include <vector>
#include <map>
using namespace std;
void oofv_rate_calculation_v1_0510(){

    string sel_true_FV_bothFGD = "((abs(selvtx_truepos[0])<874.51 && abs(selvtx_truepos[1]-55)<874.51 && selvtx_truepos[2]>136.875 && selvtx_truepos[2]<446.955) || (abs(selvtx_truepos[0])<860 && abs(selvtx_truepos[1]-55)<860 && selvtx_truepos[2]>1481.45 && selvtx_truepos[2]<1787.83))";
    string sel_true_FV_FGD1 = "(abs(selvtx_truepos[0])<874.51 && abs(selvtx_truepos[1]-55)<874.51 && selvtx_truepos[2]>136.875 && selvtx_truepos[2]<446.955)";
    string sel_true_FV_FGD2 = "(abs(selvtx_truepos[0])<860 && abs(selvtx_truepos[1]-55)<860 && selvtx_truepos[2]>1481.45 && selvtx_truepos[2]<1787.83)";
    
    string sel_reco_FV_bothFGD = "((abs(selvtx_pos[0])<874.51 && abs(selvtx_pos[1]-55)<874.51 && selvtx_pos[2]>136.875 && selvtx_pos[2]<446.955) || (abs(selvtx_pos[0])<860 && abs(selvtx_pos[1]-55)<860 && selvtx_pos[2]>1481.45 && selvtx_pos[2]<1787.83))";
    string sel_reco_FV_FGD1 = "(abs(selvtx_pos[0])<874.51 && abs(selvtx_pos[1]-55)<874.51 && selvtx_pos[2]>136.875 && selvtx_pos[2]<446.955)";
    string sel_reco_FV_FGD2 = "(abs(selvtx_pos[0])<860 && abs(selvtx_pos[1]-55)<860 && selvtx_pos[2]>1481.45 && selvtx_pos[2]<1787.83)";
  
    // TString package = "numuBkgRHC";
    TString package = "numuFHC";
    // TString package = "anumuRHC";

    TString FGD = "FGD1";
    // TString FGD = "FGD2";

    // TString variable = "costheta";
    TString variable = "pmu";
    // TString path_to_input = "/sps/t2k/quocviet/data/hl2_3.4.1_output/numuCC4piMultiPiAnalysis/prod7_V12_neut_D_2015-08-water_magnet_run8_accum2/";
    
    // TString path_to_input = "/sps/t2k/quocviet/data/hl2_3.4.1_output/numuBkgInAntiNuMode_accum2/";
    TString path_to_input = "/sps/t2k/quocviet/data/hl2_3.4.1_output/numuCCMultiPi_accum2/";
    // TString path_to_input = "/sps/t2k/quocviet/data/hl2_3.4.1_output/numuCCAnalysis_accum2";
    std::map<TString, TString> input_file;
    // input_file["numuBkgRHC"]="hl2_accum_cut_2_output_numuBkgInAntiNuMode.root";
    // input_file["numuFHC"]="hl2_accum_cut_2_output_numuCCmultiPiAnalysis.root";
    // input_file["anumuRHC"]="hl2_accum_cut_2_output_AntiNumuCCAnalysis.root";
    
    //test
    input_file["numuFHC"]="merge_numuCCMultiPi_parallel_run.root";
    
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

    //  SampleGroup run4("run4");
    // run4.AddMCSample("magnet",mc);  
    // exp.AddSampleGroup("run4",run4); 

    // TCanvas *c1 = new TCanvas("c1","c1", 800,600);
    // draw.SetTitle("CC0pi antineutrino");
    // draw.SetTitleX("p_#mu MeV");

    // draw.SetTitleY("E")

    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level[][0]>5 &&"+sel_reco_FV_FGD1);
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level[][0]>6 && "+sel_reco_FV_bothFGD);
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level[][0]>6 && "+sel_reco_FV_FGD1);
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level[][0]>6 && !"+sel_true_FV_FGD1);

    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level[0][1][0]>5 ");
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level[0][1][0]>5 && "+sel_reco_FV_FGD2);
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level[0][1][0]>5 && !"+sel_true_FV_FGD2);
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level[0][1][0]>6 && !"+sel_true_FV_FGD2);
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level[0][1][0]>6 ");
    
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level[][0]>3 && ((abs(selvtx_truepos->at(1))<874.51 && abs(selvtx_truepos->at(2)-55)<874.51 && selvtx_truepos->at(3)>136.875 && selvtx_truepos->at(3)<446.955) || (abs(selvtx_truepos->at(1))<860 && abs(selvtx_truepos->at(2)-55)<860 && selvtx_truepos->at(3)>1481.45 && selvtx_truepos->at(3)<1787.83))");
    // draw.DumpCuts(-1);

    // TCanvas *c2 = new TCanvas("c2","c2", 800,600);
    // c2->SetTitle("CC0pi OOFV");
    // // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level[][0]>5 && !"+sel_true_FV_bothFGD);
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level[][0]>5 && !"+sel_true_FV_FGD1);
    // // selvtx_truepos


    // TH1D* h1_test = (TH1D*)draw->GetLastStackTotal();
    // std::cout << "  entries   = " << h1_test->GetEntries() << std::endl;
    // double entries_h1=h1_test->GetEntries();

    // // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level[0][1][0]>5 && !"+sel_true_FV_FGD2);
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level[][0]>5 && !"+sel_true_FV_FGD1);
    // TH1D* h2_test = (TH1D*)draw->GetLastStackTotal();
    // double entries_h2=h2_test->GetEntries();
    // double rate=entries_h2/entries_h1;
    // cout<<"rate: "<<rate<<endl;


    //CC0pi
    // string accum_level_fgd1 = "[][0]>6";
    // string accum_level_fgd2 = "[0][1][0]>6";
    // string mode = "CC0pi";
    //CC0pi,  numuBkginRHC
    string accum_level_fgd1 = "[][0]>7";
    string accum_level_fgd2 = "[0][1][0]>7";
    string mode = "CC0pi";

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
        draw.SetTitle(Form("%s %s sample",mode.c_str(),package.Data()));
        draw.SetTitleX("p_#mu MeV");
        // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level"+accum_level_fgd1+" &&"+sel_reco_FV_FGD1,"","pur");
        draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd_numu_oofv", "accum_level[][0]>5 && topology==7","","pur");
        // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd_numu_oofv", "accum_level"+accum_level_fgd1+" &&"+sel_reco_FV_FGD1+"&& topology==7","","pur");
        // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level"+accum_level_fgd1);
        TH1D* h1_test = (TH1D*)draw.GetLastStackTotal();
        double entries_h1=h1_test->GetEntries();

        TCanvas *c2 = new TCanvas("c2","c2", 800,600);
        draw.SetTitle(Form("%s %s sample",mode.c_str(),package.Data()));
        draw.SetTitleX("p_#mu MeV");
        draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level"+accum_level_fgd1+" && !"+sel_true_FV_FGD1+"&&"+sel_reco_FV_FGD1);
        TH1D* h2_test = (TH1D*)draw.GetLastStackTotal();
        double entries_h2=h2_test->GetEntries();
        double rate=entries_h2/entries_h1;
        cout<<"ratefgd1: "<<rate<<endl;
        //FGD2**********************************************************
        TCanvas *c3 = new TCanvas("c3","c3", 800,600);
        draw.SetTitle(Form("%s %s sample",mode.c_str(),package.Data()));
        draw.SetTitleX("p_#mu MeV");
        draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level"+accum_level_fgd2+" &&"+sel_reco_FV_FGD2);
        // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level"+accum_level_fgd2);
        h1_test = (TH1D*)draw.GetLastStackTotal();
        entries_h1=h1_test->GetEntries();

        TCanvas *c4 = new TCanvas("c4","c4", 800,600);
        draw.SetTitle(Form("%s %s sample",mode.c_str(),package.Data()));
        draw.SetTitleX("p_#mu MeV");
        draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level"+accum_level_fgd2+" && !"+sel_true_FV_FGD2+"&&"+sel_reco_FV_FGD2);
        h2_test = (TH1D*)draw.GetLastStackTotal();
        entries_h2=h2_test->GetEntries();
        rate=entries_h2/entries_h1;
        cout<<"ratefgd2: "<<rate<<endl;
    // }

}   