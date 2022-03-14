#include <gtest/gtest.h>
#include <fstream>
#include "commands/external_command.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
static const std::string expected_result = "test \n";
#else
static const std::string expected_result = "test\n";
#endif

TEST(ExternalCommandTest, BasicLogicTest) {
  std::vector<std::string> arguments;
  arguments.emplace_back("echo test");

  std::string in_stream;
  std::stringstream err_stream;

  auto command = new shell::ExternalCommand(std::move(arguments), std::move(in_stream));
  auto result = command->execute({});

  EXPECT_EQ(result.out_stream, expected_result);
}

TEST(ExternalCommandTest, VariablesTest) {
  shell::VariablesStorage storage;
  const auto name = "VAR";
  const auto value = "test";
  storage.SetVariable(name, value);

  std::vector<std::string> arguments;
  arguments.emplace_back("echo $VAR");

  std::string in_stream;
  std::stringstream err_stream;

  auto command = new shell::ExternalCommand(std::move(arguments), std::move(in_stream));
  auto result = command->execute(storage);

  EXPECT_EQ(result.out_stream, "test\n");
}
