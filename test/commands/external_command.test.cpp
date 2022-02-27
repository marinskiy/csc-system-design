#include <gtest/gtest.h>
#include <fstream>
#include "commands/external_command.h"

TEST(ExternalCommandTest, BasicLogicTest) {
  std::vector<std::string> arguments;
  arguments.push_back("echo test");

  std::stringstream in_stream;
  std::stringstream err_stream;

  auto command = new shell::ExternalCommand(arguments, std::move(in_stream), std::move(err_stream));
  auto result = command->execute();

  EXPECT_EQ(result.out_stream.str(), "test\n");
}

