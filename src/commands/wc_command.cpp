#include "wc_command.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <iterator>

shell::WcCommand::WcCommand(std::vector<std::string> arguments,
                            std::string in_stream) :
    shell::CommandBase::CommandBase(std::move(arguments), std::move(in_stream)) {
};

shell::CommandResult shell::WcCommand::executeInternalLogic(const VariablesStorage& variables) {
  if (arguments_.size() == 0) {
    std::cerr << "wc: Need at least one argument." << std::endl;
  }

  std::ostringstream out, err;
  for (const auto &argument: arguments_) {
    auto path = std::filesystem::path(argument);

    if (!std::filesystem::exists(path)) {
      err << "wc: " << argument << ": No such file or directory" << std::endl;
      continue;
    }

    if (std::filesystem::is_directory(path)) {
      err << "wc: " << argument << ": Is a directory" << std::endl;
      continue;
    }

    size_t number_of_lines = 0;
    size_t number_of_words = 0;
    std::string line;
    std::ifstream f(path);

    while (std::getline(f, line)) {
      ++number_of_lines;
      number_of_words += countWords(line);
    }

    const auto file_size = std::filesystem::file_size(path);

    out << number_of_lines << " " << number_of_lines << " " << file_size << std::endl;
  }

  return {out.str(), err.str(), 0, false};
}

int shell::WcCommand::countWords(const std::string &s) {
  std::istringstream iss{s};
  return std::distance(std::istream_iterator<std::string>{iss},
                       std::istream_iterator<std::string>{});
}
