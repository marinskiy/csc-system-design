include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(shell_tests variables_storage.test.cpp)
target_link_libraries(shell_tests gtest_main)

include(GoogleTest)
gtest_discover_tests(shell_tests)
