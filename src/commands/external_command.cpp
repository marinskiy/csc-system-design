#include "external_command.h"
#include <iostream>
#include <fstream>

shell::CommandResult shell::ExternalCommand::executeInternalLogic(const VariablesStorage &variables) {
  std::string commandString;
  for (const auto&[name, value]: variables.GetVariables()) {
    putenv((name + "=" + value).data());
  }

  std::ostringstream out, err;
  for (int i = 0; i < arguments_.size(); i++) {
    commandString += arguments_[i] + " ";
  }
  commandString += "1>out.log 2>err.log";

  int exit_code = std::system(commandString.c_str());

  std::ifstream f("out.log");
  out << f.rdbuf();
  f.close();

  std::ifstream e("err.log");
  err << e.rdbuf();
  f.close();

  std::remove("out.log");
  std::remove("err.log");

  return {out.str(), err.str(), exit_code, false};
}

shell::ExternalCommand::ExternalCommand(std::vector<std::string> &&arguments,
                                        std::string &&in_stream) :
    shell::CommandBase::CommandBase(std::move(arguments), std::move(in_stream)) {
};
