#pragma once

#include <string>
#include <unordered_map>

namespace shell {
    class VariablesStorage {
    public:
        const std::string &GetVariable(const std::string &variable_name) const;

        void SetVariable(std::string variable_name, std::string variable_value);

        const std::unordered_map<std::string, std::string> &GetVariables() const;

        static bool IsValidEnvNameNextCharacter(char c, const std::string& prefix);

        // sets variables from an external storage. on name conflict does not override previous values
        void SetVariables(const VariablesStorage &other, bool replace_old=false);

    private:
        const std::string default_value_;
        std::unordered_map<std::string, std::string> variables_;
    };
}
