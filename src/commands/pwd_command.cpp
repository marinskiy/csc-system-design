#include "pwd_command.h"
#include <iostream>
#include <filesystem>

shell::CommandResult shell::PwdCommand::executeInternalLogic(const VariablesStorage &variables) {
  std::ostringstream out;
  out << std::filesystem::current_path().string() << std::endl;
  return {out.str(), "", 0, false};
}

shell::PwdCommand::PwdCommand(std::vector<std::string> &&arguments,
                              std::string &&in_stream) :
    shell::CommandBase::CommandBase(std::move(arguments), std::move(in_stream)) {
};

