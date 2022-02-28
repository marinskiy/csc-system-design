#include <gtest/gtest.h>
#include <fstream>
#include "commands/wc_command.h"

TEST(WcCommandTest, BasicLogicTest) {
  std::ofstream outfile("test.txt");
  outfile << "test" << std::endl;
  outfile.close();

  std::vector<std::string> arguments;
  arguments.push_back("test.txt");

  std::stringstream in_stream;
  std::stringstream err_stream;

  auto command = new shell::WcCommand(arguments, std::move(in_stream), std::move(err_stream));
  auto result = command->execute();

  EXPECT_EQ(result.out_stream.str(), "1 1 5\n");

  std::remove("test.txt");
}
