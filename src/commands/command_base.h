#pragma once

#include <string>
#include <vector>
#include <sstream>
#include "command_result.h"

namespace shell {
class CommandBase {
 public:
  CommandBase(std::vector<std::string> arguments, std::unique_ptr<std::stringstream> in_stream, std::unique_ptr<std::stringstream> err_stream);
  CommandResult execute();

  virtual ~CommandBase() = default;
 protected:
  virtual CommandResult executeInternalLogic() = 0;

  std::vector<std::string> arguments_;
  bool isExecuted = false;

  std::unique_ptr<std::stringstream> in_stream_;
  std::unique_ptr<std::stringstream> out_stream_;
  std::unique_ptr<std::stringstream> err_stream_;
};
}
