#include <gtest/gtest.h>
#include <fstream>
#include "commands/cat_command.h"

TEST(CatCommandTest, BasicLogicTest) {
  std::ofstream outfile ("test.txt");
  outfile << "test";
  outfile.close();

  std::vector<std::string> arguments;
  arguments.push_back("test.txt");

  std::string in_stream;

  auto command = new shell::CatCommand(std::move(arguments), std::move(in_stream));
  auto result = command->execute({});

  EXPECT_EQ(result.out_stream, "test");

  std::remove("test.txt");
}

