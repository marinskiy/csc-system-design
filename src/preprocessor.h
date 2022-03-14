#pragma once

#include <iostream>  // TODO(morokei): remove

#include <string>
#include <vector>

#include "variables_storage.h"
#include "command_params.h"

namespace shell {
class ParsingError : public std::runtime_error {
 public:
  ParsingError(const std::string &what) : std::runtime_error(what) {}
};

class PreprocessedPipelineString {
 public:
  void AddCommand(CommandParams command);

  const std::vector<CommandParams> &GetCommands() const;

 private:
  std::vector<CommandParams> commands_;
};

class Preprocessor {
 public:
  PreprocessedPipelineString ParseCommandString(
      const std::string &input,
      const VariablesStorage &variables_storage);

 private:
  enum class ParsingState {
    NO_QUOTE_OPEN = 0,
    SINGLE_QUOTE_OPEN = 1,
    DOUBLE_QUOTE_OPEN = 2,
  };

  const char SINGLE_QUOTE = '\'';
  const char DOUBLE_QUOTE = '\"';
  const char COMMAND_SEPARATOR = '|';
  const char ENV_VARIABLE_START = '$';

  PreprocessedPipelineString Tokenize(const std::string &command_string);
  std::string Substitute(
          const std::string& input,
          const VariablesStorage &variables_storage);
};
}
