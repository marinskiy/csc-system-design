#include <gtest/gtest.h>
#include "variables_storage.h"

TEST(VariablesStorageTest, DefaultValueTest) {
  shell::VariablesStorage storage;
  const auto name = "name";
  const auto value = "value";
  storage.SetVariable(name, value);
  EXPECT_EQ(storage.GetVariable(name), value);
}
