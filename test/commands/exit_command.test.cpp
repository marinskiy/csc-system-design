#include <gtest/gtest.h>
#include "commands/exit_command.h"

TEST(ExitCommandTest, BasicLogicTest) {
  std::vector<std::string> arguments;
  std::stringstream in_stream;
  std::stringstream err_stream;

  auto command = new shell::ExitCommand(arguments, std::move(in_stream), std::move(err_stream));
  auto result = command->execute();

  EXPECT_EQ(result.need_exit, true);
}
