#include <gtest/gtest.h>
#include <fstream>
#include "commands/external_command.h"

TEST(ExternalCommandTest, BasicLogicTest) {
  std::vector<std::string> arguments;
  arguments.emplace_back("echo test");

  std::string in_stream;
  std::stringstream err_stream;

  auto command = new shell::ExternalCommand(std::move(arguments), std::move(in_stream));
  auto result = command->execute({});

  EXPECT_EQ(result.out_stream, "test\n");
}

