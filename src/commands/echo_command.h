#pragma once
#include "command_base.h"

namespace shell {
class EchoCommand : public CommandBase {
 public:
    EchoCommand(std::vector<std::string>&& arguments,
                std::string&& in_stream);

private:
    CommandResult executeInternalLogic(const VariablesStorage& variables) override;
};
}
