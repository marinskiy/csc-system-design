#pragma once
#include "command_base.h"

namespace shell {
class WcCommand : public CommandBase {
 public:
  WcCommand(std::vector<std::string> arguments,
             std::stringstream in_stream,
             std::stringstream err_stream);
 private:
  CommandResult executeInternalLogic() override;
  int countWords(const std::string &s);
};
}
