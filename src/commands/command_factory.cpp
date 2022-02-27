#include "command_factory.h"
#include "echo_command.h"

shell::CommandBase *shell::CommandFactory::createCommand(CommandParams params,
                                                         std::unique_ptr<std::stringstream> in_stream,
                                                         std::unique_ptr<std::stringstream> err_stream) {
  auto tokens = params.GetTokens();
  if (tokens.size() == 0) {
    //TODO: throw exception
  }

  std::string command_name = tokens[0];
  tokens.erase(tokens.begin());

  if (command_name == "echo") {
    return new shell::EchoCommand(tokens, std::move(in_stream), std::move(err_stream));
  } else {
    // TODO: replace with ExternalCommand
    return new shell::EchoCommand(tokens, std::move(in_stream), std::move(err_stream));
  }
}
