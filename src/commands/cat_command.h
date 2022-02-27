#pragma once
#include "command_base.h"

namespace shell {
class CatCommand : public CommandBase {
 public:
  CatCommand(std::vector<std::string> arguments,
             std::stringstream in_stream,
             std::stringstream err_stream);
 private:
  CommandResult executeInternalLogic() override;
};
}
