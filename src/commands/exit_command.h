#pragma once
#include "command_base.h"

namespace shell {
/** Command to exit the shell */
class ExitCommand : public CommandBase {
 public:
  /**
   * Constructor of ExitCommand
   * @param arguments - arguments - will be ignored
   * @param in_stream - input string - will be ignored
   */
  ExitCommand(std::vector<std::string> &&arguments,
              std::string &&in_stream);

 private:
  CommandResult executeInternalLogic(const VariablesStorage &variables) override;
};
}
