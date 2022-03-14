#pragma once

#include <memory>

namespace shell {
/** Structure for storing command results */
struct CommandResult {
  std::string out_stream;
  std::string err_stream;
  int exit_code = 0;
  bool need_exit = false;
};
}
