#include "variables_storage.h"

#include <string>
#include <unordered_map>

namespace shell {
    const std::string &VariablesStorage::GetVariable(const std::string &variable_name) const {
        auto value = variables_.find(variable_name);
        return value == variables_.end() ? default_value_ : value->second;
    }

    void VariablesStorage::SetVariable(std::string variable_name, std::string variable_value) {
        variables_[std::move(variable_name)] = std::move(variable_value);
    }

    const std::unordered_map<std::string, std::string> &VariablesStorage::GetVariables() const {
        return variables_;
    }

    bool VariablesStorage::IsValidEnvNameNextCharacter(char c, const std::string& prefix) {
       return std::isalpha(c) || c == '_' || (!prefix.empty() && std::isdigit(c));
    }

    void VariablesStorage::SetVariables(const VariablesStorage &other, bool replace_old) {
        for (const auto&[name, value]: other.variables_) {
            if (replace_old || !variables_.count(name)) {
                SetVariable(name, value);
            }
        }
    }
}

