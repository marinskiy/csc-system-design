#pragma once

#include <sstream>
#include "variables_storage.h"
#include "preprocessor.h"

struct CommandResult {
  std::stringstream out_stream;
  std::stringstream err_stream;
  int exit_code = 0;
  bool need_exit = false;
};

class Executor {
 public:
  CommandResult Execute(const ExecutionPipeline& pipeline, VariablesStorage& variables) {
    return CommandResult();
  }   
};
