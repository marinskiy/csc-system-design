#include <gtest/gtest.h>
#include <filesystem>
#include "commands/pwd_command.h"

TEST(PwdCommandTest, BasicLogicTest) {
  std::vector<std::string> arguments;
  std::stringstream in_stream;
  std::stringstream err_stream;

  auto command = new shell::PwdCommand(arguments, std::move(in_stream), std::move(err_stream));
  auto result = command->execute();

  EXPECT_EQ(result.out_stream.str(), std::filesystem::current_path().string() + '\n');
}
