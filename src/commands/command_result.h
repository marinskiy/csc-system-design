#pragma once

#include <memory>

namespace shell {
struct CommandResult {
  std::stringstream out_stream;
  std::stringstream err_stream;
  int exit_code = 0;
  bool need_exit = false;
};
}
