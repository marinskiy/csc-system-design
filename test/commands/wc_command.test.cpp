#include <gtest/gtest.h>
#include <fstream>
#include "commands/wc_command.h"
#include "variables_storage.h"

TEST(WcCommandTest, BasicLogicTest) {
  std::ofstream outfile("test.txt");
  outfile << "test" << std::endl;
  outfile.close();

  std::vector<std::string> arguments;
  arguments.push_back("test.txt");

  std::string in_stream;

  auto command = new shell::WcCommand(std::move(arguments), std::move(in_stream));
  auto result = command->execute(shell::VariablesStorage{});

  EXPECT_EQ(result.out_stream, "1 1 5\n");

  std::remove("test.txt");
}
