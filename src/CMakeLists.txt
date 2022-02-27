add_library(shell_lib STATIC
        commands/command_result.h
        commands/cat_command.h commands/cat_command.cpp
        commands/command_base.h commands/command_base.cpp
        commands/echo_command.h commands/echo_command.cpp
        commands/exit_command.h commands/exit_command.cpp
        commands/external_command.h commands/external_command.cpp
        commands/pwd_command.h commands/pwd_command.cpp
        executor.h
        preprocessor.h
        command_params.h
        variables_storage.h
        commands/command_factory.h commands/command_factory.cpp)

add_executable(shell
        main.cpp)
