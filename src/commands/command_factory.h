#pragma once

#include <memory>
#include "command_base.h"
#include "echo_command.h"
#include "command_params.h"

namespace shell {
class CommandFactory {
 public:
  CommandBase *createCommand(CommandParams command_string,
                             std::unique_ptr<std::stringstream> in_stream,
                             std::unique_ptr<std::stringstream> err_stream);
};
}
