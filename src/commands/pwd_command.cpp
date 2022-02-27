#include "pwd_command.h"
#include <iostream>
#include <filesystem>

shell::PwdCommand::PwdCommand(std::vector<std::string> arguments,
                                std::stringstream in_stream,
                                std::stringstream err_stream) :
    shell::CommandBase::CommandBase(std::move(arguments), std::move(in_stream), std::move(err_stream)) {
};

shell::CommandResult shell::PwdCommand::executeInternalLogic() {
  out_stream_ << std::filesystem::current_path().string() << std::endl;
  return {std::move(out_stream_), std::move(err_stream_), 0, false};
}

