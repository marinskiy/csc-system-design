#include "variables_storage.h"

#include <string>
#include <unordered_map>

namespace shell {
    const std::string &VariablesStorage::GetVariable(const std::string &variable_name) const {
        auto value = variables_.find(variable_name);
        return value == variables_.end() ? default_value_ : value->second;
    }

    void VariablesStorage::SetVariable(std::string variable_name, std::string variable_value) {
        variables_.emplace(std::move(variable_name), std::move(variable_value));
    }

    const std::unordered_map<std::string, std::string> &VariablesStorage::GetVariables() const {
        return variables_;
    }

    void VariablesStorage::SetVariables(const VariablesStorage &other) {
        for (const auto&[name, value]: other.variables_) {
            if (!variables_.count(name)) {
                SetVariable(name, value);
            }
        }
    }
}

