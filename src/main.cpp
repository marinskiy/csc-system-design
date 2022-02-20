#include <iostream>
#include <unordered_map>

#include "executor.h"
#include "preprocessor.h"
#include "variables_storage.h"


class ReadExecPrintLoop {
 public:
  void run() {
    std::string command_string;
    while (getline(std::cin, command_string)) {
      auto command = preprocessor_.ParseCommandString(command_string, variables_storage_);
      auto result = executor_.Execute(command, variables_storage_);
      if (result.need_exit) {
        break;
      }
      std::cout << "done " << command_string << std::endl;
    }
  }

 private:
  VariablesStorage variables_storage_;
  Preprocessor preprocessor_;
  Executor executor_;
};

int main() {
  ReadExecPrintLoop read_exec_print_loop;
  read_exec_print_loop.run();
}
