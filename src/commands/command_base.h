#pragma once

#include <string>
#include <vector>
#include <sstream>
#include "command_result.h"

namespace shell {
class CommandBase {
 public:
  CommandBase(std::vector<std::string> arguments, std::stringstream in_stream, std::stringstream err_stream);
  virtual CommandResult execute() = 0;
 protected:
  std::vector<std::string> arguments_;
  std::stringstream in_stream_;
  std::stringstream err_stream_;
};
}
