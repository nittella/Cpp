#pragma once

#include <chrono>
#include <iostream>
#include <string>

using namespace std;
using namespace std::chrono;

#define CONCAT(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) CONCAT(lineno)

#define LOG_DURATION(message)         \
LogDuration UNIQ_ID(__LINE__) {message}


class LogDuration{
public:
    explicit LogDuration(const string& msg = "")
            : start(steady_clock::now()),
              message(msg + ": "){}

    ~LogDuration(){
        auto finish = steady_clock::now();
        auto duration = finish - start;
        cerr << message <<
             duration_cast<milliseconds>(duration).count()
             << " ms" << endl;
    }
private:
    steady_clock::time_point start;
    string message;
};
