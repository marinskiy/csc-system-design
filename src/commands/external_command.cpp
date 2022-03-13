#include "external_command.h"
#include <iostream>
#include <boost/process/io.hpp>
#include <boost/process/system.hpp>

shell::CommandResult shell::ExternalCommand::executeInternalLogic(const VariablesStorage &variables) {
  std::string commandString;
  for (const auto&[name, value]: variables.GetVariables()) {
    commandString += name + "=" + value + " ";
  }

  std::stringstream out_stream, err_stream;
  for (int i = 0; i < arguments_.size(); i++) {
    commandString += arguments_[i] + " ";
  }

  boost::process::opstream in;
  boost::process::ipstream out, err;

  in << in_stream_;

  boost::process::system(commandString.c_str(),
                         boost::process::std_out > out,
                         boost::process::std_err > err,
                         boost::process::std_in < in);
  int exit_code = std::system(commandString.c_str());

  out_stream << out.rdbuf();
  err_stream << err.rdbuf();

  return {out_stream.str(), err_stream.str(), exit_code, false};
}

shell::ExternalCommand::ExternalCommand(std::vector<std::string> &&arguments,
                                        std::string &&in_stream) :
    shell::CommandBase::CommandBase(std::move(arguments), std::move(in_stream)) {
};
