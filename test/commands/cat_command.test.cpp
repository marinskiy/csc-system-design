#include <gtest/gtest.h>
#include <fstream>
#include "commands/cat_command.h"

TEST(CatCommandTest, BasicLogicTest) {
  std::ofstream outfile("test.txt");
  outfile << "test";
  outfile.close();

  std::vector<std::string> arguments;
  arguments.push_back("test.txt");

  std::string in_stream;

  auto command = new shell::CatCommand(std::move(arguments), std::move(in_stream));
  auto result = command->execute({});

  EXPECT_EQ(result.out_stream, "test");
  EXPECT_EQ(result.err_stream, "");
  EXPECT_EQ(result.exit_code, 0);
  EXPECT_EQ(result.need_exit, false);

  std::remove("test.txt");
}

