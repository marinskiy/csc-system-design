#pragma once
#include "command_base.h"

namespace shell {
class PwdCommand : public CommandBase {
 public:
  PwdCommand(std::vector<std::string> arguments,
              std::stringstream in_stream,
              std::stringstream err_stream);
 private:
  CommandResult executeInternalLogic() override;
};
}
