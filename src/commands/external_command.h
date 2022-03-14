#pragma once
#include "command_base.h"

namespace shell {
class ExternalCommand : public CommandBase {
 private:
  CommandResult executeInternalLogic(const VariablesStorage &variables) override;

 public:
  ExternalCommand(std::vector<std::string> &&arguments,
                  std::string &&in_stream);
};
}
