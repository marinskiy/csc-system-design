#pragma once

#include <sstream>
#include "variables_storage.h"
#include "preprocessor.h"
#include "commands/command_result.h"
#include "commands/command_base.h"

namespace shell {
class Executor {
 public:
  CommandResult Execute(const ExecutionPipeline &pipeline, VariablesStorage &variables) {
    return CommandResult();
  }
};
}
