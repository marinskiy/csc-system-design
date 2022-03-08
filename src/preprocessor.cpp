#include "preprocessor.h"

#include <string>
#include <vector>

#include "variables_storage.h"
#include "command_params.h"

namespace shell {
    void PreprocessedPipelineString::AddCommand(CommandParams command) {
        if (command.GetTokens().empty())
            throw ParsingError("Invalid command: command params cannot be empty");
        commands_.push_back(std::move(command));
    }

    const std::vector<CommandParams> &PreprocessedPipelineString::GetCommands() const {
        return commands_;
    }

    PreprocessedPipelineString Preprocessor::ParseCommandString(
            const std::string &input,
            const VariablesStorage &variables_storage) {
        const auto command_string = Substitute(input, variables_storage);
        return Tokenize(command_string);
    }

    PreprocessedPipelineString Preprocessor::Tokenize(const std::string &command_string) {
        PreprocessedPipelineString pipeline;
        ParsingState state = ParsingState::NO_QUOTE_OPEN;
        CommandParams current_command;
        std::string current_token;
        for (char c: command_string) {
            if (state == ParsingState::NO_QUOTE_OPEN) {
                if (c == COMMAND_SEPARATOR || std::isspace(c)) {
                    current_command.AddToken(std::move(current_token));
                    current_token = "";
                    if (c == COMMAND_SEPARATOR) {
                        pipeline.AddCommand(std::move(current_command));
                        current_command = CommandParams();
                    }
                } else if (c == SINGLE_QUOTE || c == DOUBLE_QUOTE) {
                    state = c == SINGLE_QUOTE ? ParsingState::SINGLE_QUOTE_OPEN : ParsingState::DOUBLE_QUOTE_OPEN;
                } else {
                    current_token.push_back(c);
                }
            } else {
                char closure_symbol = state == ParsingState::SINGLE_QUOTE_OPEN ? SINGLE_QUOTE : DOUBLE_QUOTE;
                if (c == closure_symbol)
                    state = ParsingState::NO_QUOTE_OPEN;
                else
                    current_token.push_back(c);
            }
        }
        if (state != ParsingState::NO_QUOTE_OPEN)
            throw ParsingError("Invalid command: state != NO_QUOTE_OPEN");
        current_command.AddToken(current_token);
        if (current_command.GetTokens().empty()) {
            if (!pipeline.GetCommands().empty())
                throw ParsingError("Invalid command: command params cannot be empty");
            return pipeline;
        }
        pipeline.AddCommand(current_command);
        return pipeline;
    }

    std::string Preprocessor::Substitute(
            const std::string &input,
            const VariablesStorage &variables_storage) {
        std::string result;
        std::string env_variable_name;
        ParsingState state = ParsingState::NO_QUOTE_OPEN;
        bool collect_env_name = false;
        for (char c : input) {
            if (collect_env_name && !VariablesStorage::IsValidEnvNameNextCharacter(c, env_variable_name)) {
                result += variables_storage.GetVariable(std::move(env_variable_name));
                collect_env_name = false;
            }
            if (c == ENV_VARIABLE_START && 
                    (state == ParsingState::NO_QUOTE_OPEN || state == ParsingState::DOUBLE_QUOTE_OPEN)) {
                env_variable_name = "";
                collect_env_name = true;
            } else {
                if (collect_env_name)
                    env_variable_name.push_back(c);
                else
                    result.push_back(c);
            }
            if (c == DOUBLE_QUOTE) {
                if (state == ParsingState::DOUBLE_QUOTE_OPEN)
                    state = ParsingState::NO_QUOTE_OPEN;
                else
                    state = ParsingState::DOUBLE_QUOTE_OPEN;
            }
        }
        std::cout << "MOROKEI " << env_variable_name << std::endl; 
        std::cout << "MOROKEI: " << variables_storage.GetVariable(env_variable_name) << std::endl;
        std::cout << variables_storage.GetVariables().size() << std::endl;
        if (collect_env_name)
            result += variables_storage.GetVariable(env_variable_name);
        return result;
    }
}
