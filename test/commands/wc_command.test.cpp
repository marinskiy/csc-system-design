#include <gtest/gtest.h>
#include <fstream>
#include "commands/wc_command.h"
#include "variables_storage.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    static const std::string expected_result = "1 1 6\n";
#else
    static const std::string expected_result = "1 1 5\n";
#endif

TEST(WcCommandTest, BasicLogicTest) {
  std::ofstream outfile("test.txt");
  outfile << "test" << std::endl;
  outfile.close();

  std::vector<std::string> arguments;
  arguments.push_back("test.txt");

  std::string in_stream;

  auto command = new shell::WcCommand(std::move(arguments), std::move(in_stream));
  auto result = command->execute(shell::VariablesStorage{});

  EXPECT_EQ(result.out_stream, expected_result);

  std::remove("test.txt");
}

TEST(WcCommandTest, InStreamTest) {
  std::stringstream stream;
  stream << "test" << std::endl;
  std::vector<std::string> arguments;

  auto command = new shell::WcCommand(std::move(arguments), stream.str());
  auto result = command->execute(shell::VariablesStorage{});

  EXPECT_EQ(result.out_stream, expected_result);
}