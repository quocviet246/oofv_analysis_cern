#include <string>
#include <vector>
​
void fourpi_plots() {
	
    gROOT->SetBatch(); //Stops it from spamming windows when drawing
	DrawingTools* draw = new DrawingTools("/home/t2k/aspeers/PROD7_validation/testing/MultiPiAnalysis_TEST.root",4); //Initialises DrawingTools with a random .root file
​
	// Create an experiment with name "nd280"
    Experiment exp("nd280");
​
    DataSample* prod_7 = new DataSample("/data/aspeers/4pi_Selection/mcp/microTrees/P7_V12_FHC_FGD2_default_settings.root");
    SampleGroup p_7("p_7");
    p_7.AddMCSample("magnet", prod_7);
	exp.AddSampleGroup("p_7", p_7);
​
    float win_scale = 0.75;
    int n_wide(2);
    int n_high(2);
​
    const char * sample_names[12] = {"Fwd_CC0Pi0p","Fwd_CC0PiNp","Bwd_CC0Pi0p","Bwd_CC0PiNp","HAFwd_CC0Pi0p","HAFwd_CC0PiNp","HABwd_CC0Pi0p","HABwd_CC0PiNp","Fwd_CC1Pi","HAFwd_CC1Pi","Fwd_CCOther","CCPhoton"};
    const char * accum_levels[12] = {   "[0]>8"   ,   "[1]>8"   ,   "[2]>8"   ,   "[3]>8"   ,    "[4]>8"    ,    "[5]>8"    ,   "[6]>8"   ,   "[7]>8"   ,  "[8]>7"  ,   "[9]>7"   ,   "[10]>7"  , "[11]>6" };
    const char * categories[2] = {"distribution", "effpurity"};
	
	TCanvas* canvas = new TCanvas("canvas", "canvas", 750*n_wide*win_scale, 500*n_high*win_scale);
	
	plotMomCos(exp, accum_levels, sample_names, categories);
}
​
void plotMomCos(Experiment exp, const char * accum_levels[], const char * sample_names[], const char * categories[]) {
	
	DrawingTools* draw = new DrawingTools("/home/t2k/aspeers/PROD7_validation/testing/MultiPiAnalysis_TEST.root",4);
	const char * variables[2] = {"mom","costheta"};
	const char * FGDs[2] = {"FGD1", "FGD2"};
	
	int f = 2; //FGD Number
	
	for(int j = 0; j<1; j++){ // loop over distribution and efficiency&purity
		for(int i = 0; i<2; i++){ // loop over mom,cos
			for(int k = 0; k<12; k++){ // loop over samples
	
				if(j==0){ //Distributions
				if(i==0){ //Momentum
					draw->SetLegendPos("tr");
					draw->SetTitleX("Reconstructed p_{#mu} [MeV/c]");
					draw->SetTitleY("Events");
					draw->SetTitle(Form("%s_%s_%s_%s",FGDs[f-1],sample_names[k],variables[i],categories[j]));
					
					draw->Draw(exp,"all","magnet","selmu_mom",50,0,5000,"topology",Form("accum_level[0]%s",accum_levels[k]),"","OVER NOAUTOLABELS");
					//hist = (TH1D*)draw->GetLastHisto();
					//hist -> SetTitle("title");
					}
				if(i==1){ //cos(theta)
					draw->SetLegendPos("tl");
					draw->SetTitleX("Reconstructed cos#theta_{#mu}");
					draw->SetTitleY("Events");
					draw->SetTitle(Form("%s_%s_%s_%s",FGDs[f-1],sample_names[k],variables[i],categories[j]));
					
					draw->Draw(exp,"all","magnet","selmu_costheta",50, -1, 1,"topology",Form("accum_level[0]%s",accum_levels[k]),"","UNDER NOAUTOLABELS");
					//hist = (TH1D*)draw->GetLastHisto();
					//hist -> SetTitle("title");
					}
				}
					canvas->SaveAs(Form("Plots/%s_%s_%s_%s.pdf",FGDs[f-1],sample_names[k],variables[i],categories[j]));
			}
		}
	}
}