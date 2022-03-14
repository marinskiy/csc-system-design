#include "command_base.h"
#include <iostream>
#include "variables_storage.h"

shell::CommandBase::CommandBase(std::vector<std::string> &&arguments,
                                std::string &&in_stream) :
    arguments_(arguments), in_stream_(in_stream) {};

shell::CommandResult shell::CommandBase::execute(const VariablesStorage &variables) {
  if (isExecuted) {
    // TODO: throw exception;
  }
  isExecuted = true;

  return executeInternalLogic(variables);
};
