#include "read_exec_print.h"

namespace shell {
    void ReadExecPrintLoop::run() {
        std::string command_string;
        while (getline(std::cin, command_string)) {
            auto command = preprocessor_.ParseCommandString(command_string, variables_storage_);
            auto result = executor_.Execute(command, variables_storage_);
            std::cout << result.out_stream;
            if (result.exit_code != 0) {
                std::cerr << "Exited with code " << result.exit_code << ": ";
            }
            if (!result.err_stream.empty()) {
                std::cerr << result.err_stream;
            }
            if (result.need_exit) {
                break;
            }
        }
    }
}