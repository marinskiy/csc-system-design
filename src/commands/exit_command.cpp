#include "exit_command.h"
#include "command_base.h"
#include <iostream>

shell::ExitCommand::ExitCommand(std::vector<std::string> arguments,
                                std::stringstream in_stream,
                                std::stringstream err_stream) :
    shell::CommandBase::CommandBase(std::move(arguments), std::move(in_stream), std::move(err_stream)) {
};

shell::CommandResult shell::ExitCommand::executeInternalLogic() {
  return {std::move(out_stream_), std::move(err_stream_), 0, true};
}

