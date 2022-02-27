#include "cat_command.h"
#include <iostream>
#include <filesystem>
#include <fstream>

shell::CatCommand::CatCommand(std::vector<std::string> arguments,
                              std::stringstream in_stream,
                              std::stringstream err_stream) :
    shell::CommandBase::CommandBase(std::move(arguments), std::move(in_stream), std::move(err_stream)) {
};

shell::CommandResult shell::CatCommand::executeInternalLogic() {
  if (arguments_.size() == 0) {
    std::cerr << "cat: Need at least one argument." << std::endl;
  }

  for (const auto &argument: arguments_) {
    auto path = std::filesystem::path(argument);

    if (!std::filesystem::exists(path)) {
      err_stream_ << "cat: " << argument << ": No such file or directory" << std::endl;
      continue;
    }

    if (std::filesystem::is_directory(path)) {
      err_stream_ << "cat: " << argument << ": Is a directory" << std::endl;
      continue;
    }

    std::ifstream f(path);
    out_stream_ << f.rdbuf();
    f.close();

  }

  return {std::move(out_stream_), std::move(err_stream_), 0, false};
}
