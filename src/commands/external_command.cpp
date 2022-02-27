#include "external_command.h"
#include <iostream>
#include <fstream>

shell::ExternalCommand::ExternalCommand(std::vector<std::string> arguments,
                                std::stringstream in_stream,
                                std::stringstream err_stream) :
    shell::CommandBase::CommandBase(std::move(arguments), std::move(in_stream), std::move(err_stream)) {
};

shell::CommandResult shell::ExternalCommand::executeInternalLogic() {
  std::string commandString;
  for (int i = 0; i < arguments_.size(); i++) {
    commandString += arguments_[i] + " ";
  }
  commandString += "1>out.log 2>err.log";

  int exit_code = std::system(commandString.c_str());

  std::ifstream f("out.log");
  out_stream_ << f.rdbuf();
  f.close();

  std::ifstream e("err.log");
  err_stream_ << e.rdbuf();
  f.close();

  std::remove("out.log");
  std::remove("err.log");

  return {std::move(out_stream_), std::move(err_stream_), exit_code, false};
}

