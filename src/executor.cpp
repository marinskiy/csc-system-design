#include "variables_storage.h"
#include "preprocessor.h"
#include "commands/command_result.h"
#include "executor.h"

namespace shell {
    CommandResult Executor::Execute(const PreprocessedPipelineString &pipeline, VariablesStorage &variables) {
        auto commands = pipeline.GetCommands();
        std::string in;
        CommandResult global_result;
        for (auto &command: commands) {
            auto local = GetLocatEnvironment(command);
            if (command.Empty()) {
                if (commands.size() == 1) {
                    variables.SetVariables(local, /*replace_old=*/true);
                    break;
                } else {
                    continue;
                }
            }
            local.SetVariables(variables);
            auto func = factory_.createCommand(command, std::move(in));
            auto result = func->execute(local);
            in = result.out_stream;
            global_result.err_stream.append(result.err_stream);
            global_result.exit_code = result.exit_code;
            global_result.need_exit = result.need_exit;
            global_result.out_stream = result.out_stream;
        }

        return global_result;
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
