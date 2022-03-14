#pragma once

#include <sstream>
#include "variables_storage.h"
#include "preprocessor.h"
#include "commands/command_result.h"
#include "commands/command_base.h"
#include "commands/command_factory.h"

namespace shell {
    class Executor {
    public:
        CommandResult Execute(const PreprocessedPipelineString &pipeline, VariablesStorage &variables);

    private:
        VariablesStorage GetLocatEnvironment(CommandParams &command) ;

        CommandFactory factory_;
    };
}
