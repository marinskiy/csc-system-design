#include "cat_command.h"
#include <iostream>
#include <filesystem>
#include <fstream>

shell::CatCommand::CatCommand(std::vector<std::string>&& arguments,
                              std::string&& in_stream) :
    shell::CommandBase::CommandBase(std::move(arguments), std::move(in_stream)) {
};

shell::CommandResult shell::CatCommand::executeInternalLogic(const VariablesStorage& variables) {
  if (arguments_.empty()) {
    std::cerr << "cat: Need at least one argument." << std::endl;
  }

  std::ostringstream out, err;
  for (const auto &argument: arguments_) {
    auto path = std::filesystem::path(argument);

    if (!std::filesystem::exists(path)) {
      err << "cat: " << argument << ": No such file or directory" << std::endl;
      continue;
    }

    if (std::filesystem::is_directory(path)) {
      err << "cat: " << argument << ": Is a directory" << std::endl;
      continue;
    }

    std::ifstream f(path);
    out << f.rdbuf();
    f.close();
  }

  out << in_stream_;

  return {out.str(), err.str(), 0, false};
}