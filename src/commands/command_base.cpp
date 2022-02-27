#include "command_base.h"
#include <iostream>

shell::CommandBase::CommandBase(std::vector<std::string> arguments,
                                std::stringstream in_stream,
                                std::stringstream err_stream) :
    arguments_(arguments), in_stream_(std::move(in_stream)), err_stream_(std::move(err_stream)) {};

shell::CommandResult shell::CommandBase::execute() {
  if (isExecuted) {
    // TODO: throw exception;
  }
  isExecuted = true;

  std::streambuf *old_cout_stream_buf = std::cout.rdbuf();
  std::cout.rdbuf(out_stream_.rdbuf());

  std::streambuf *old_cerr_stream_buf = std::cerr.rdbuf();
  std::cerr.rdbuf(err_stream_.rdbuf());

  auto result = executeInternalLogic();

  std::cout.rdbuf(old_cout_stream_buf);
  std::cerr.rdbuf(old_cerr_stream_buf);

  return result;
};
