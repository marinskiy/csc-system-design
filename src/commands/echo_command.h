#pragma once
#include "command_base.h"

namespace shell {
/** Command to print its arguments to output */
class EchoCommand : public CommandBase {
 public:
  /**
   * Constructor of EchoCommand
   * @param arguments - arguments to be printed to output
   * @param in_stream - input string - will be ignored
   */
  EchoCommand(std::vector<std::string> &&arguments,
              std::string &&in_stream);

 private:
  CommandResult executeInternalLogic(const VariablesStorage &variables) override;
};
}
