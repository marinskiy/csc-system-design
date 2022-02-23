add_executable(shell
        main.cpp
        commands/command_base.h commands/command_base.cpp
        commands/command_result.h
        commands/echo_command.h commands/echo_command.cpp
        executor.h
        preprocessor.h
        variables_storage.h)
