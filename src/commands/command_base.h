#pragma once

#include <string>
#include <vector>
#include <sstream>
#include "command_result.h"
#include "variables_storage.h"

namespace shell {
class CommandBase {
 public:
  CommandBase(std::vector<std::string> &&arguments, std::string &&in_stream);
  CommandResult execute(const VariablesStorage &variables);

  virtual ~CommandBase() = default;
 protected:
  virtual CommandResult executeInternalLogic(const VariablesStorage &variables) = 0;

  std::vector<std::string> arguments_;
  bool isExecuted = false;

  std::string in_stream_;
};
}
