#include "echo_command.h"
#include <iostream>

shell::CommandResult shell::EchoCommand::executeInternalLogic(const VariablesStorage& variables) {
    std::ostringstream out, err;
  for (int i = 0; i < arguments_.size(); i++) {
    out << arguments_[i];
    if (i != arguments_.size() - 1) {
      out << " ";
    }
    else {
      out << std::endl;
    }
  }

  return {out.str(), err.str(), 0, false};
}

shell::EchoCommand::EchoCommand(std::vector<std::string>&& arguments,
                                std::string&& in_stream) :
        shell::CommandBase::CommandBase(std::move(arguments), std::move(in_stream)) {
};

