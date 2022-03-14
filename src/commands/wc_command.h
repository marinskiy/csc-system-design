#pragma once
#include "command_base.h"

namespace shell {
/** Command to print to output the number of lines, number of words and size of the files passed in the arguments or if no arguments passed of the input string*/
class WcCommand : public CommandBase {
 public:
  /**
   * Constructor of WcCommand
   * @param arguments - vetor of file names
   * @param in_stream - input string
   */
  WcCommand(std::vector<std::string> arguments,
            std::string in_stream);
 private:
  CommandResult executeInternalLogic(const VariablesStorage &variables) override;
  int countWords(const std::string &s);
  std::tuple<size_t, size_t> calculateStreamStats(std::istream &stream);
};
}
