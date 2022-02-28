add_library(shell_lib STATIC
        commands/command_result.h
        commands/cat_command.h commands/cat_command.cpp
        commands/command_base.h commands/command_base.cpp
        commands/echo_command.h commands/echo_command.cpp
        commands/exit_command.h commands/exit_command.cpp
        commands/external_command.h commands/external_command.cpp
        commands/pwd_command.h commands/pwd_command.cpp
        commands/wc_command.h commands/wc_command.cpp
        executor.h executor.cpp
        preprocessor.h preprocessor.cpp
        command_params.h
        variables_storage.h variables_storage.cpp
        read_exec_print.h read_exec_print.cpp
        commands/command_factory.h commands/command_factory.cpp)

add_executable(shell main.cpp)
target_link_libraries(shell shell_lib)
