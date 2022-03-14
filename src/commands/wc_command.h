#pragma once
#include "command_base.h"

namespace shell {
class WcCommand : public CommandBase {
 public:
  WcCommand(std::vector<std::string> arguments,
             std::string in_stream);
 private:
  CommandResult executeInternalLogic(const VariablesStorage& variables) override;
  int countWords(const std::string &s);
  std::tuple<size_t, size_t> calculateStreamStats(std::istream& stream);
};
}
