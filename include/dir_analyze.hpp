// Copyright 2021 <geraldy12319@gamil.com>

#ifndef INCLUDE_DIR_ANALYZE_HPP_
#define INCLUDE_DIR_ANALYZE_HPP_

#include <string>
#include <boost/filesystem.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <regex>
#include <iomanip>

namespace fs = boost::filesystem;

class Analyzer{
 public:
  explicit Analyzer(const std::string& path);
  ~Analyzer();

  void Files_Info(std::ostream& out = std::cout) const;
  void Accounts_Stats(std::ostream& out = std::cout) const;

 private:
  std::stringstream Account_to_str(const fs::path& elem, const size_t& n) const;
 private:
  fs::path file_path;
  std::set<std::string> nameAccounts;
  std::vector<fs::path> pathArr;
};

#endif // INCLUDE_DIR_ANALYZE_HPP_
