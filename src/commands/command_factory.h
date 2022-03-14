#pragma once

#include <memory>
#include "command_base.h"
#include "echo_command.h"
#include "command_params.h"

namespace shell {
/** Factory for creating commands */
class CommandFactory {
 public:
  /**
   * @brief Factory method for creating command
   * @param command_string - command parameters
   * @param in_stream - string with command input
   * @return created command
   */
  CommandBase *createCommand(CommandParams command_string,
                             std::string in_stream);
};
}
