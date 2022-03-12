#include <gtest/gtest.h>

#include "executor.h"
#include "variables_storage.h"

TEST(ExecutorTest, BasicLogicTest) {
    shell::VariablesStorage storage;
    shell::CommandParams params{{"echo", "lalala"}};
    shell::PreprocessedPipelineString pipeline;
    pipeline.AddCommand(params);
    shell::Executor executor{};
    const auto result = executor.Execute(pipeline, storage);
    EXPECT_EQ(result.out_stream, "lalala\n");
    EXPECT_EQ(result.err_stream, "");
    EXPECT_EQ(result.exit_code, 0);
    EXPECT_EQ(result.need_exit, false);
}
