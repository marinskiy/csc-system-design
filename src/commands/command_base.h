#pragma once

#include <string>
#include <vector>
#include <sstream>
#include "command_result.h"

namespace shell {
class CommandBase {
 public:
  CommandBase(std::vector<std::string> arguments, std::stringstream in_stream, std::stringstream err_stream);
  CommandResult execute();

  virtual ~CommandBase() = default;
 protected:
  virtual CommandResult executeInternalLogic() = 0;

  std::vector<std::string> arguments_;
  bool isExecuted = false;

  std::stringstream in_stream_;
  std::stringstream out_stream_;
  std::stringstream err_stream_;
};
}
