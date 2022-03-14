#include <gtest/gtest.h>
#include <filesystem>
#include "commands/pwd_command.h"

TEST(PwdCommandTest, BasicLogicTest) {
  std::vector<std::string> arguments;
  std::string in_stream;

  auto command = new shell::PwdCommand(std::move(arguments), std::move(in_stream));
  auto result = command->execute({});

  EXPECT_EQ(result.out_stream, std::filesystem::current_path().string() + '\n');
  EXPECT_EQ(result.err_stream, "");
  EXPECT_EQ(result.exit_code, 0);
  EXPECT_EQ(result.need_exit, false);
}
