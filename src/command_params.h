#pragma once

#include <deque>
#include <vector>
#include <optional>

namespace shell {
    class CommandParams {
    public:
        void AddToken(std::string token) {
            if (!token.empty())
                command_params_.push_back(std::move(token));
        }

        std::optional<std::pair<std::string, std::string>> PopVariableDefinition() {
            if (command_params_.empty()) {
                return std::nullopt;
            }
            const auto &token = *command_params_.begin();
            std::string env_variable_name = "";
            for (char c : token) {
                if (VariablesStorage::IsValidEnvNameNextCharacter(c, env_variable_name))
                    env_variable_name.push_back(c);
                else
                    break;
            }
            size_t len = env_variable_name.size();
            if (len && len < token.size() && token[len] == '=') {
                const auto result = std::make_pair(env_variable_name, token.substr(len + 1));
                command_params_.pop_front();
                return result;
            }
            return std::nullopt;
        }

        CommandParams() = default;

        explicit CommandParams(std::vector<std::string> &&tokens) : command_params_(tokens.begin(), tokens.end()) {}

        std::vector<std::string> GetTokens() const {
            return {command_params_.begin(), command_params_.end()};
        }

        bool empty() const {
            return command_params_.empty();
        }

    private:
        std::deque<std::string> command_params_;
    };
}
