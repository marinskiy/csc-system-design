#include <gtest/gtest.h>
#include "commands/exit_command.h"

TEST(ExitCommandTest, BasicLogicTest) {
  std::vector<std::string> arguments;
  std::string in_stream;

  auto command = new shell::ExitCommand(std::move(arguments), std::move(in_stream));
  auto result = command->execute({});

  EXPECT_EQ(result.out_stream, "");
  EXPECT_EQ(result.err_stream, "");
  EXPECT_EQ(result.exit_code, 0);
  EXPECT_EQ(result.need_exit, true);
}
