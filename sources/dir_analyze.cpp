// Copyright 2021 <geraldy12319@gamil.com>

#include <dir_analyze.hpp>

Analyzer::Analyzer(const std::string& path) {
  if (!path.empty()) {
    boost::system::error_code err;
    if (fs::exists(path, err)) {
      file_path = path;
    } else {
      throw fs::filesystem_error("Nothing exist at the path", err);
    }
  } else {
    file_path = fs::current_path();
  }
  const std::regex pattern(
      "^(balance_)\\d\\d\\d\\d\\d\\d\\d\\d_\\d\\d\\d\\d\\d\\d\\d\\d");
  for (const auto& dir : fs::directory_iterator(file_path)) {
    if (fs::is_directory(dir.path())) {
      for (const auto& file : fs::directory_iterator{dir.path()}) {
        if (fs::is_regular_file(file) && (file.path().extension() == ".txt") &&
            (std::regex_search(file.path().stem().string(), pattern))) {
          pathArr.push_back(file.path());
          nameAccounts.insert(file.path().stem().string().substr(8, 8));
        }
      }
    }
  }
}

void Analyzer::Files_Info(std::ostream& out) const{
  for (const auto& path : pathArr) {
    out << std::left << std::setw(10)
        << path.parent_path().filename().string() << " "
        << path.filename().string() << '\n';
  }
}

std::stringstream Analyzer::Account_to_str(const fs::path& elem,
                                         const size_t& n) const{
  std::stringstream ss;
  ss << "broker: " << std::left << std::setw(8)
     << elem.parent_path().filename().string()
     << " | account: " << elem.stem().string().substr(8, 8)
     << " | files: " << std::setw(3) << n
     << " | lastdate: " << elem.stem().string().substr(17, 8);
  return ss;
}

void Analyzer::Accounts_Stats(std::ostream& out) const{
  for (const auto & el : nameAccounts) {
    std::vector<fs::path> temp;

    size_t n = 0;
    for (const auto& i : pathArr) {
      if (el == i.stem().string().substr(8, 8)) {
        n++;
        temp.push_back(i);
      }
    }
    auto recent = std::max_element(
        temp.begin(), temp.end(), [](const fs::path& lhs, const fs::path& rhs) {
          return lhs.stem().string().substr(17, 8) <
                 rhs.stem().string().substr(17, 8);
        });
    out << Account_to_str(*recent, n).str() << std::endl;
  }
}

Analyzer::~Analyzer() = default;
