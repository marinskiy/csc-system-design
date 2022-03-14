#pragma once

#include <string>
#include <vector>
#include <sstream>
#include "command_result.h"
#include "variables_storage.h"

namespace shell {
/** Base class for all commands. All new commands shod be inherited from it */
class CommandBase {
 public:
  /**
   * Command base constructor
   * @param arguments - command arguments
   * @param in_stream  - string with command input
   */
  CommandBase(std::vector<std::string> &&arguments, std::string &&in_stream);
  /**
   * Execute command
   * @param variables - local environment variables
   * @return result of command execution
   */
  CommandResult execute(const VariablesStorage &variables);

  /**
   * Destructor
   */
  virtual ~CommandBase() = default;
 protected:
  virtual CommandResult executeInternalLogic(const VariablesStorage &variables) = 0;

  std::vector<std::string> arguments_;
  bool isExecuted = false;

  std::string in_stream_;
};
}
