#pragma once
#include "command_base.h"

namespace shell {
class EchoCommand : public CommandBase {
 public:
  EchoCommand(std::vector<std::string> arguments,
              std::unique_ptr<std::stringstream> in_stream,
              std::unique_ptr<std::stringstream> err_stream);
 private:
  CommandResult executeInternalLogic() override;
};
}
