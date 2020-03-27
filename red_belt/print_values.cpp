#include "test_runner.h"

#include <ostream>
using namespace std;

template <typename X, typename Y>
void PrintValues(ostream& os, const X& x, const Y& y){
    os << x << endl;
    os << y << endl;
}

#define PRINT_VALUES(out, x, y) PrintValues(out, x, y)

int main() {
    PRINT_VALUES(cout, 5, "red belt");
    return 0;
}
