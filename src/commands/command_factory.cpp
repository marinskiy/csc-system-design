#include "command_factory.h"
#include "cat_command.h"
#include "echo_command.h"
#include "exit_command.h"
#include "external_command.h"
#include "pwd_command.h"

shell::CommandBase *shell::CommandFactory::createCommand(CommandParams params,
                                                         std::stringstream in_stream,
                                                         std::stringstream err_stream) {
  auto tokens = params.GetTokens();
  if (tokens.size() == 0) {
    //TODO: throw exception
  }

  std::string command_name = tokens[0];

  if (command_name == "cat" || command_name == "echo" || command_name == "exit" || command_name == "pwd") {
    tokens.erase(tokens.begin());
  }

  if (command_name == "cat") {
    return new shell::CatCommand(tokens, std::move(in_stream), std::move(err_stream));
  } else if (command_name == "echo") {
    return new shell::EchoCommand(tokens, std::move(in_stream), std::move(err_stream));
  } else if (command_name == "exit") {
    return new shell::ExitCommand(tokens, std::move(in_stream), std::move(err_stream));
  } else if (command_name == "pwd") {
    return new shell::PwdCommand(tokens, std::move(in_stream), std::move(err_stream));
  } else {
    return new shell::ExternalCommand(tokens, std::move(in_stream), std::move(err_stream));
  }
}
