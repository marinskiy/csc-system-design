#include <gtest/gtest.h>
#include <fstream>
#include "commands/cat_command.h"

TEST(CatCommandTest, BasicLogicTest) {
  std::ofstream outfile ("test.txt");
  outfile << "test";
  outfile.close();

  std::vector<std::string> arguments;
  arguments.push_back("test.txt");

  std::stringstream in_stream;
  std::stringstream err_stream;

  auto command = new shell::CatCommand(arguments, std::move(in_stream), std::move(err_stream));
  auto result = command->execute();

  EXPECT_EQ(result.out_stream.str(), "test");

  std::remove("test.txt");
}

