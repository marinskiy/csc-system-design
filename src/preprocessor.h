#pragma once

#include <string>
#include <vector>

#include "variables_storage.h"

struct CommandParams {
  std::vector<std::string> command_params;
};

struct ExecutionPipeline {
  std::vector<CommandParams> commands;
};

class Preprocessor {
 public:
  ExecutionPipeline ParseCommandString(
      const std::string& command_string,
      const VariablesStorage& variables_storage) {
    return ExecutionPipeline();
  }
};
