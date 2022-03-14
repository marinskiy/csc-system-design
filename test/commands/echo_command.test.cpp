#include <gtest/gtest.h>
#include "commands/echo_command.h"

TEST(EchoCommandTest, BasicLogicTest) {
  std::vector<std::string> arguments;
  arguments.push_back("a");
  arguments.push_back("b");

  std::string in_stream;

  auto command = new shell::EchoCommand(std::move(arguments), std::move(in_stream));
  auto result = command->execute({});

  EXPECT_EQ(result.out_stream, "a b\n");
  EXPECT_EQ(result.err_stream, "");
  EXPECT_EQ(result.exit_code, 0);
  EXPECT_EQ(result.need_exit, false);
}

