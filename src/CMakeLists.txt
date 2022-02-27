add_library(shell_lib STATIC
        commands/command_result.h
        commands/command_base.h commands/command_base.cpp
        commands/echo_command.h commands/echo_command.cpp
        commands/exit_command.h commands/exit_command.cpp
        executor.h
        preprocessor.h
        command_params.h
        variables_storage.h
        commands/command_factory.h commands/command_factory.cpp)

add_executable(shell
        main.cpp)
