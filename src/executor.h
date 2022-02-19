#pragma once

#include "variables_storage.h"
#include "preprocessor.h"

struct CommandResult {
  std::string output;
};

struct PipelineResult {
  CommandResult command_result;
  bool exit;
};


class Executor {
 public:
  PipelineResult Execute(const ExecutionPipeline& pipeline, VariablesStorage& variables) {
    return PipelineResult();
  }   
};
