#pragma once
#include <iostream>
#include <unordered_map>

#include "executor.h"
#include "preprocessor.h"
#include "variables_storage.h"

namespace shell {
    class ReadExecPrintLoop {
    public:
        void run();

    private:
        VariablesStorage variables_storage_;
        Preprocessor preprocessor_;
        Executor executor_;
    };
}