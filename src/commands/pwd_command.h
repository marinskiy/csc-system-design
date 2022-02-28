#pragma once
#include "command_base.h"

namespace shell {
class PwdCommand : public CommandBase {
 private:
    CommandResult executeInternalLogic(const VariablesStorage& variables) override;

public:
    PwdCommand(std::vector<std::string>&& arguments,
               std::string&& in_stream);
};
}
