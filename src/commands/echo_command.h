#pragma once
#include "command_base.h"

namespace shell {
class EchoCommand: CommandBase {
  EchoCommand(std::vector<std::string> arguments, std::stringstream in_stream, std::stringstream err_stream);
  CommandResult execute() override;
};
}
