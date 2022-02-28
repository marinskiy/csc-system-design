#include "exit_command.h"
#include <iostream>

shell::CommandResult shell::ExitCommand::executeInternalLogic(const VariablesStorage& variables) {
  return {"","", 0, true};
}

shell::ExitCommand::ExitCommand(std::vector<std::string>&& arguments,
                                std::string&& in_stream) :
        shell::CommandBase::CommandBase(std::move(arguments), std::move(in_stream)) {
};

