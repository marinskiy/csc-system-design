#pragma once

#include <memory>

namespace shell {
struct CommandResult {
  std::unique_ptr<std::stringstream> out_stream;
  std::unique_ptr<std::stringstream> err_stream;
  int exit_code = 0;
  bool need_exit = false;
};
}
