// Copyright 2021 <geraldy12319@gamil.com>

#include <dir_analyze.hpp>

int main(int argc, char* argv[]){
  std::string path;

  if(argc > 1) path = argv[1];

  Analyzer A(path);
  A.Files_Info();
  A.Accounts_Stats();
  return 0;
}