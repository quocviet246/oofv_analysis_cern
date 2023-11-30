#include <TH1D.h>
void plot_numubkginRHC(){

    string sel_true_FV_bothFGD = "((abs(selvtx_truepos[0])<874.51 && abs(selvtx_truepos[1]-55)<874.51 && selvtx_truepos[2]>136.875 && selvtx_truepos[2]<446.955) || (abs(selvtx_truepos[0])<860 && abs(selvtx_truepos[1]-55)<860 && selvtx_truepos[2]>1481.45 && selvtx_truepos[2]<1787.83))";
    string sel_true_FV_FGD1 = "(abs(selvtx_truepos[0])<874.51 && abs(selvtx_truepos[1]-55)<874.51 && selvtx_truepos[2]>136.875 && selvtx_truepos[2]<446.955)";
    string sel_true_FV_FGD2 = "(abs(selvtx_truepos[0])<860 && abs(selvtx_truepos[1]-55)<860 && selvtx_truepos[2]>1481.45 && selvtx_truepos[2]<1787.83)";
    
    string sel_reco_FV_bothFGD = "((abs(selvtx_pos[0])<874.51 && abs(selvtx_pos[1]-55)<874.51 && selvtx_pos[2]>136.875 && selvtx_pos[2]<446.955) || (abs(selvtx_pos[0])<860 && abs(selvtx_pos[1]-55)<860 && selvtx_pos[2]>1481.45 && selvtx_pos[2]<1787.83))";
    string sel_reco_FV_FGD1 = "(abs(selvtx_pos[0])<874.51 && abs(selvtx_pos[1]-55)<874.51 && selvtx_pos[2]>136.875 && selvtx_pos[2]<446.955)";
    string sel_reco_FV_FGD2 = "(abs(selvtx_pos[0])<860 && abs(selvtx_pos[1]-55)<860 && selvtx_pos[2]>1481.45 && selvtx_pos[2]<1787.83)";
  
    
    Experiment exp("nd280");
    DrawingTools draw("/sps/t2k/quocviet/data/final_merge_dir/hl2_accum_cut_2_output_numuBkgInAntiNuMode.root");
    DataSample* mc = new DataSample("/sps/t2k/quocviet/data/final_merge_dir/hl2_accum_cut_2_output_numuBkgInAntiNuMode.root");
    SampleGroup run4("run4");
    run4.AddMCSample("magnet",mc);  
    exp.AddSampleGroup("run4",run4); 
    TCanvas *c1 = new TCanvas("c1","c1", 800,600);
    draw.SetTitle("CC0pi antineutrino");
    draw.SetTitleX("p_#mu MeV");
    // draw.SetTitleY("E")

    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level[][0]>6 && !"+FV_bothFGD);
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level[][0]>6 && "+sel_reco_FV_bothFGD);
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level[][0]>6 && "+sel_reco_FV_FGD1);
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level[][0]>6 && !"+sel_true_FV_FGD1);

    draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level[0][1][0]>5 ");
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level[0][1][0]>5 && "+sel_reco_FV_FGD2);
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level[0][1][0]>5 && !"+sel_true_FV_FGD2);
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level0][1][0]>6 && !"+sel_true_FV_FGD2);
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "fgd2reaction", "accum_level0][1][0]>6 ");
    
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level[][0]>3 && ((abs(selvtx_truepos->at(1))<874.51 && abs(selvtx_truepos->at(2)-55)<874.51 && selvtx_truepos->at(3)>136.875 && selvtx_truepos->at(3)<446.955) || (abs(selvtx_truepos->at(1))<860 && abs(selvtx_truepos->at(2)-55)<860 && selvtx_truepos->at(3)>1481.45 && selvtx_truepos->at(3)<1787.83))");
    // draw.DumpCuts();

    // TCanvas *c2 = new TCanvas("c2","c2", 800,600);
    // c2->SetTitle("CC0pi OOFV");
    // // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level[][0]>5 && !"+sel_true_FV_bothFGD);
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level[][0]>5 && !"+sel_true_FV_FGD1);
    // // selvtx_truepos


    TH1D* h1_test = (TH1D*)draw->GetLastStackTotal();
    //  std::cout << "  entries   = " << (TH1D*)draw->GetEntries() << std::endl;
     std::cout << "  entries   = " << h1_test->GetEntries() << std::endl;

    // const char* inputDirName= "/sps/t2k/quocviet/data/test_cut_2";
    // Experiment exp("nd280");
    // DrawingTools draw(Form("%s/oa_nt_beam_90400000-0050_h7wnkjw4ebsm_anal_000_magnet201011airrun4-bsdv01_2.root", inputDirName));
    // DataSample* r5mc = new DataSample(Form("%s/oa_nt_beam_90400000-0050_h7wnkjw4ebsm_anal_000_magnet201011airrun4-bsdv01_2.root", inputDirName));
    // DataSample* r6mc = new DataSample(Form("%s/oa_nt_beam_90400014-0001_sku4k6jp2pa2_anal_000_magnet201011airrun4-bsdv01_2.root", inputDirName));
    // // DataSample* r6mc = new DataSample("/data/osullivan/Analysis/total/P6T-run6.root");
    // SampleGroup run5("run5");                                                                                                                                                                                                             
    // run5.AddMCSample("magnet",r5mc);                                                                                                                                                                                                      
    // SampleGroup run6("run6");                                                                                                                                                                                                           
    // run6.AddMCSample("magnet",r6mc);
    // exp.AddSampleGroup("run5",run5);                                                                                                                                                                                                      
    // exp.AddSampleGroup("run6",run6);
    // draw.Draw(exp, "selmu_mom", 200, 0, 6000, "reaction", "accum_level[][0]>1");
    // // draw.Draw(exp,"all","selmu_mom/1000",19,5,"topology2","(accum_level[][][0]>7 || accum_level[][][1]>7)"); 

}