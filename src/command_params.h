#pragma once

namespace shell {
class CommandParams {
 public:
  void AddToken(std::string token) {
    if (!token.empty())
      command_params_.push_back(std::move(token));
  }

  const std::vector<std::string> &GetTokens() const {
    return command_params_;
  }

 private:
  std::vector<std::string> command_params_;
};
}