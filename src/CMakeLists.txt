add_executable(shell main.cpp)
add_library(shell_lib STATIC variables_storage.h preprocessor.h executor.h)
set_target_properties(shell_lib PROPERTIES LINKER_LANGUAGE CXX)