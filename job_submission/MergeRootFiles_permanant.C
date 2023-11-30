#include <TFile.h>
#include <TTree.h>
#include <TSystemDirectory.h>
#include <TSystemFile.h>
#include <TString.h>
 #include <iostream>
#include <vector>


void copyAddresses(TTree* inputTree, TTree* outputTree) {
    TObjArray* branches = inputTree->GetListOfBranches();
    for (int i = 0; i < branches->GetEntries(); i++) {
        TBranch* branch = (TBranch*)branches->At(i);
        inputTree->SetBranchAddress(branch->GetName(), branch->GetAddress());
        outputTree->Branch(branch->GetName(), branch->GetAddress(), branch->GetTitle());
    }
}
// void MergeRootFiles(const char* outputFileName = "/sps/t2k/quocviet/data/merge_file_accum_2_test.root", const char* inputDirName= "/sps/t2k/quocviet/data/test_cut_2") {
//     std::vector<TFile*> inputFiles;
//     std::vector<TTree*> inputTrees;

//     // Open all the input files and get their TTrees
//     TSystemDirectory dir(inputDirName, inputDirName);
//     TList* files = dir.GetListOfFiles();
//     if (files) {
//         TSystemFile* file;
//         TString fileName;
//         TIter next(files);
//         while ((file=(TSystemFile*)next())) {
//             fileName = file->GetName();
//             if (!file->IsDirectory() && fileName.EndsWith(".root")) {
//                 TString inputFileName = TString::Format("%s/%s", inputDirName, fileName.Data());
//                 TFile* inputFile = new TFile(inputFileName, "READ");
//                 if (!inputFile->IsOpen()) {
//                     std::cerr << "Error: could not open input file " << inputFileName << std::endl;
//                     continue;
//                 }
//                 inputFiles.push_back(inputFile);
//                 std::cout << "Opened input file " << inputFileName << std::endl;

//                 // Loop over all the TTree objects in the input file and add them to the output file
//                 TList* trees = inputFile->GetListOfKeys();
//                 if (trees) {
//                     TKey* key;
//                     TIter next(trees);
//                     while ((key=(TKey*)next())) {
//                         TObject* obj = key->ReadObj();
//                         if (obj->InheritsFrom("TTree")) {
//                             TTree* inputTree = (TTree*)obj;
//                             inputTrees.push_back(inputTree);
//                             std::cout << "Added TTree " << inputTree->GetName() << " from file " << inputFileName << std::endl;
//                         }
//                     }
//                 }

//                 // Close the input file
//                 inputFile->Close();
//                 delete inputFile;
//             }
//         }
//     }

//     // Merge all the TTree objects into a new output file
//     TFile* outputFile = new TFile(outputFileName, "RECREATE");
//     for (int i = 0; i < inputTrees.size(); i++) {
//         TTree* inputTree = inputTrees[i];
//         TTree* outputTree = new TTree(inputTree->GetName(), inputTree->GetTitle());
//         copyAddresses(inputTree, outputTree);
//         outputTree->CopyEntries(inputTree);
//         outputTree->Write();
//         std::cout << "Merged TTree " << inputTree->GetName() << " into output file" << std::endl;
//     }
//     outputFile->Close();

//     std::cout << "Merged files saved to " << outputFileName << std::endl;
// }

// void MergeRootFiles(const char* outputFileName = "/sps/t2k/quocviet/data/merge_file_accum_2.root", const char* inputDirName= "/sps/t2k/quocviet/data/hl2_accum_cut_2_output") {
void MergeRootFiles(const char* outputFileName = "/sps/t2k/quocviet/data/merge_file_accum_2_test.root", const char* inputDirName= "/sps/t2k/quocviet/data/test_cut_2") {

  std::vector<TFile*> inputFiles;
  std::vector<TTree*> inputTrees;

  // Open all the input files and get their TTrees
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
        inputFiles.push_back(inputFile);
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
              inputTrees.push_back(inputTree);
              std::cout << "Added TTree " << inputTree->GetName() << " from file " << inputFileName << std::endl;
            }
          }
        }
        inputFile->Close();
        // delete inputFile;
      }
    }
  }

  // Merge all the TTree objects into a new output file
  TFile* outputFile = new TFile(outputFileName, "RECREATE");
  for (int i = 0; i < inputTrees.size(); i++) {
    TTree* inputTree = inputTrees[i];
    TTree* outputTree = inputTree->CloneTree(-1, "fast"); // Use "fast" option for large TTrees
    outputTree->Write();
    std::cout << "Merged TTree " << inputTree->GetName() << " into output file" << std::endl;
  }
  outputFile->Close();

  // Clean up
  // for (int i = 0; i < inputFiles.size(); i++) {
  //   TFile* inputFile = inputFiles[i];
  //   inputFile->Close();
  //   delete inputFile;
  // }
  std::cout << "Merged files saved to " << outputFileName << std::endl;
}
