#include <gtest/gtest.h>

#include "preprocessor.h"
#include "variables_storage.h"

auto run_simple_preprocessor(const std::string& command, const shell::VariablesStorage& variables_storage) {
    shell::Preprocessor preprocessor;
    auto pipeline = preprocessor.ParseCommandString("echo $a", variables_storage);
    auto commands = pipeline.GetCommands();
    return pipeline.GetCommands()[0].GetTokens();
}


TEST(PreprocessorTest, BasicLogicTest) {
    shell::VariablesStorage variables_storage;
    variables_storage.SetVariable("a", "10");
    EXPECT_EQ(run_simple_preprocessor("echo $a", variables_storage), std::vector<std::string>({"echo", "10"}));
}
