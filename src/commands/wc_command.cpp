#include "wc_command.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <iterator>

shell::WcCommand::WcCommand(std::vector<std::string> arguments,
                            std::stringstream in_stream,
                            std::stringstream err_stream) :
    shell::CommandBase::CommandBase(std::move(arguments), std::move(in_stream), std::move(err_stream)) {
};

shell::CommandResult shell::WcCommand::executeInternalLogic() {
  if (arguments_.size() == 0) {
    std::cerr << "wc: Need at least one argument." << std::endl;
  }

  for (const auto &argument: arguments_) {
    auto path = std::filesystem::path(argument);

    if (!std::filesystem::exists(path)) {
      err_stream_ << "wc: " << argument << ": No such file or directory" << std::endl;
      continue;
    }

    if (std::filesystem::is_directory(path)) {
      err_stream_ << "wc: " << argument << ": Is a directory" << std::endl;
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

    out_stream_ << number_of_lines << " " << number_of_lines << " " << file_size << std::endl;
  }

  return {std::move(out_stream_), std::move(err_stream_), 0, false};
}

int shell::WcCommand::countWords(const std::string &s) {
  std::istringstream iss{s};
  return std::distance(std::istream_iterator<std::string>{iss},
                       std::istream_iterator<std::string>{});
}
