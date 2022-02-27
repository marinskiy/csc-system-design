#include "command_base.h"
#include <iostream>

shell::CommandBase::CommandBase(std::vector<std::string> arguments,
                                std::stringstream in_stream,
                                std::stringstream err_stream) :
    arguments_(arguments), in_stream_(std::move(in_stream)), err_stream_(std::move(err_stream)) {};

shell::CommandResult shell::CommandBase::execute() {
  if (isExecuted) {
    // TODO: throw exception;
  }
  isExecuted = true;

  return executeInternalLogic();
};
