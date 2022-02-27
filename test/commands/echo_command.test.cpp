#include <gtest/gtest.h>
#include "commands/echo_command.h"

TEST(EchoCommandTest, BasicLogicTest) {
  std::vector<std::string> arguments;
  arguments.push_back("a");
  arguments.push_back("b");

  auto in_stream = std::make_unique<std::stringstream>();
  auto err_stream = std::make_unique<std::stringstream>();

  auto command = new shell::EchoCommand(arguments, std::move(in_stream), std::move(err_stream));
  auto result = command->execute();

  EXPECT_EQ(result.out_stream->str(), "a b");
}

