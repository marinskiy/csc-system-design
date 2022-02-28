#pragma once

#include <deque>

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
            int i = 0;
            for (; i < token.size() && IsValidNameCharacter(token[i]); ++i) {}
            if (i > 0 && i < token.size() && token[i + 1] == '=') {
                const auto result = std::make_pair(token.substr(0, i), token.substr(i + 1));
                command_params_.pop_front();
                return result;
            }
            return std::nullopt;
        }

        CommandParams() = default;

        explicit CommandParams(std::vector<std::string> &&tokens) : command_params_(tokens.begin(), tokens.end()) {}

        const std::vector<std::string> GetTokens() const {
            return {command_params_.begin(), command_params_.end()};
        }

    private:
        static bool IsValidNameCharacter(const char symbol) {
            return (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') ||
                   (symbol >= '0' && symbol <= '9') || symbol == '_';
        }

        std::deque<std::string> command_params_;
    };
}