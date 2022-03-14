#pragma once
#include "command_base.h"

namespace shell {
/** Command to print to the output the contents of the files passed in the arguments */
class CatCommand : public CommandBase {
 public:
  /**
   * Constructor of CatCommand
   * @param arguments - vector of file names
   * @param in_stream- input string - will be ignored
   */
  CatCommand(std::vector<std::string> &&arguments, std::string &&in_stream);
 private:
  CommandResult executeInternalLogic(const VariablesStorage &variables) override;
};
}
