#pragma once

#include <string>
#include <unordered_map>

class VariablesStorage {
 public:
  const std::string& GetVariable(const std::string& variable_name) const {
    auto value = variables_.find(variable_name);
    return value == variables_.end() ? default_value_ : value->second;
  }

  void SetVariable(std::string variable_name, std::string variable_value) {
      variables_.emplace(std::move(variable_name), std::move(variable_value));
  }

 private:
  const std::string default_value_ = "";
  std::unordered_map<std::string, std::string> variables_;
};
