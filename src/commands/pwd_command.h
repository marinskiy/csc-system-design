#pragma once
#include "command_base.h"

namespace shell {
/** Command to print to output current direcory */
class PwdCommand : public CommandBase {
 public:
  /**
   * Constructor of PwdCommand
   * @param arguments - arguments - will be ignored
   * @param in_stream - input string - will be ignored
   */
  PwdCommand(std::vector<std::string> &&arguments,
             std::string &&in_stream);
 private:
  CommandResult executeInternalLogic(const VariablesStorage &variables) override;

};
}
