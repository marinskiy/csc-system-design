#pragma once

#include <sstream>
#include "variables_storage.h"
#include "preprocessor.h"

struct CommandResult {
  std::stringstream outStream;
  std::stringstream errStream;
  int exitCode = 0;
  bool needExit = false;
};

class Executor {
 public:
  CommandResult Execute(const ExecutionPipeline& pipeline, VariablesStorage& variables) {
    return CommandResult();
  }   
};
