#include "echo_command.h"
#include <iostream>

shell::EchoCommand::EchoCommand(std::vector<std::string> arguments,
                                std::stringstream in_stream,
                                std::stringstream err_stream) :
    shell::CommandBase::CommandBase(std::move(arguments), std::move(in_stream), std::move(err_stream)) {
};

shell::CommandResult shell::EchoCommand::executeInternalLogic() {

  for (int i = 0; i < arguments_.size(); i++) {
    out_stream_ << arguments_[i];
    if (i != arguments_.size() - 1) {
      out_stream_ << " ";
    }
    else {
      out_stream_ << std::endl;
    }
  }

  return {std::move(out_stream_), std::move(err_stream_), 0, false};
}

