#include "variables_storage.h"
#include "preprocessor.h"
#include "commands/command_result.h"
#include "executor.h"

namespace shell {
    CommandResult Executor::Execute(const PreprocessedPipelineString &pipeline, VariablesStorage &variables) {
        auto commands = pipeline.GetCommands();
        for (auto &command: commands) {
            auto local = GetLocatEnvironment(command);
            local.SetVariables(variables);
            if (commands.size() == 1 && command.empty()) {
                variables.SetVariables(local, /*replace_old=*/true);
                return CommandResult();
            }
            auto func = factory_.createCommand(command, "");
            auto result = func->execute(local);
            return result;
        }
        return CommandResult();
    }

    VariablesStorage Executor::GetLocatEnvironment(CommandParams &command) {
        VariablesStorage local;
        while (true) {
            const auto var = command.PopVariableDefinition();
            if (!var) {
                break;
            }
            local.SetVariable(var->first, var->second);
        }
        return local;
    }
}
