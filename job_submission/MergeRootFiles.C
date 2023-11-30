void MergeRootFiles(const char* outputFileName = "/sps/t2k/quocviet/data/merge_file_accum_2_test.root", const char* inputDirName= "/sps/t2k/quocviet/data/test_cut_2") {

  std::vector<TTree*> outputTrees;
  TFile* outputFile = new TFile(outputFileName, "RECREATE");

  // Loop over all the input files
  TSystemDirectory dir(inputDirName, inputDirName);
  TList* files = dir.GetListOfFiles();
  if (files) {
    TSystemFile* file;
    TString fileName;
    TIter next(files);
    while ((file=(TSystemFile*)next())) {
      fileName = file->GetName();
      if (!file->IsDirectory() && fileName.EndsWith(".root")) {
        TString inputFileName = TString::Format("%s/%s", inputDirName, fileName.Data());
        TFile* inputFile = new TFile(inputFileName, "READ");
        if (!inputFile->IsOpen()) {
          std::cerr << "Error: could not open input file " << inputFileName << std::endl;
          continue;
        }
        std::cout << "Opened input file " << inputFileName << std::endl;

        // Loop over all the TTree objects in the input file and add them to the output file
        TList* trees = inputFile->GetListOfKeys();
        if (trees) {
          TKey* key;
          TIter next(trees);
          while ((key=(TKey*)next())) {
            TObject* obj = key->ReadObj();
            if (obj->InheritsFrom("TTree")) {
              TTree* inputTree = (TTree*)obj;
              TTree* outputTree = (TTree*)inputTree->CloneTree(-1, "fast");
              outputTrees.push_back(outputTree);
              std::cout << "Added TTree " << inputTree->GetName() << " from file " << inputFileName << " to output file" << std::endl;
            }
          }
        }
        inputFile->Close();
        delete inputFile;
      }
    }
  }

  // Write all the TTree objects to the output file
  for (int i = 0; i < outputTrees.size(); i++) {
    TTree* outputTree = outputTrees[i];
    outputTree->SetDirectory(outputFile);
    outputTree->Write();
    std::cout << "Wrote TTree " << outputTree->GetName() << " to output file" << std::endl;
  }

  outputFile->Close();
  delete outputFile;

  std::cout << "Merged files saved to " << outputFileName << std::endl;
}
