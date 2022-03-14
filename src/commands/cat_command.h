#pragma once
#include "command_base.h"

namespace shell {
class CatCommand : public CommandBase {
 public:
  CatCommand(std::vector<std::string> &&arguments, std::string &&in_stream);
 private:
  CommandResult executeInternalLogic(const VariablesStorage &variables) override;
};
}
