#pragma once
#include "command_base.h"

namespace shell {
class ExternalCommand : public CommandBase {
 public:
  ExternalCommand(std::vector<std::string> arguments,
              std::stringstream in_stream,
              std::stringstream err_stream);
 private:
  CommandResult executeInternalLogic() override;
};
}
