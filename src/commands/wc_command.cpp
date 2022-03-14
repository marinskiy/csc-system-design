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
  std::ostringstream out, err;

  if (arguments_.size() == 0) {
    std::istringstream in(in_stream_);
    auto [number_of_lines, number_of_words] = calculateStreamStats(in);
    const auto file_size = in_stream_.size();
    out << number_of_lines << " " << number_of_words << " " << file_size << std::endl;
  }
  else {
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

      std::ifstream f(path);
      auto[number_of_lines, number_of_words] = calculateStreamStats(f);
      const auto file_size = std::filesystem::file_size(path);
      out << number_of_lines << " " << number_of_words << " " << file_size << std::endl;
    }
  }

  return {out.str(), err.str(), 0, false};
}

int shell::WcCommand::countWords(const std::string &s) {
  std::istringstream iss{s};
  return std::distance(std::istream_iterator<std::string>{iss},
                       std::istream_iterator<std::string>{});
}

std::tuple<size_t, size_t> shell::WcCommand::calculateStreamStats(std::istream& stream) {
  size_t number_of_lines = 0;
  size_t number_of_words = 0;

  std::string line;
  while (std::getline(stream, line)) {
    ++number_of_lines;
    number_of_words += countWords(line);
  }

  return {number_of_lines, number_of_words};
}