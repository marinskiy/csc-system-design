#pragma once
#include "command_base.h"

namespace shell {
/** Command to execute te command outside the shell */
class ExternalCommand : public CommandBase {
 private:
  CommandResult executeInternalLogic(const VariablesStorage &variables) override;

 public:
  /**
   * Constructor of ExternalCommand
   * @param arguments - vector of arguments of command. The first argument is the external command name
   * @param in_stream - input string
   */
  ExternalCommand(std::vector<std::string> &&arguments,
                  std::string &&in_stream);
};
}
