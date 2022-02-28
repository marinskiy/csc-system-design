#pragma once

#include <memory>
#include "command_base.h"
#include "echo_command.h"
#include "command_params.h"

namespace shell {
class CommandFactory {
 public:
  CommandBase *createCommand(CommandParams command_string,
                             std::string&& in_stream);
};
}
