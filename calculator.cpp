#include "calculator.h"
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    long long a_2 = a;
    long long b_2 = b;
    if (a_2 + b_2 > std::numeric_limits<int>::max() or  a_2 + b_2 < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Overflow");
    }
    return a + b;
    // TODO
}

int Calculator::sub(int a, int b) {
    // TODO
    long long a_2 = a;
    long long b_2 = b;
    if (a_2 - b_2 > std::numeric_limits<int>::max() or  a_2 - b_2 < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Overflow");
    }
    return a - b;
}

int Calculator::mul(int a, int b) {
    long long a_2 = a;
    long long b_2 = b;
    if (a_2 * b_2 > std::numeric_limits<int>::max() or  a_2 * b_2 < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Overflow");
    }

    return a * b;
}

int Calculator::div(int a, int b) {
    // TODO
    if (b==0) {
        throw std::invalid_argument("Division by zero");
    }
    long long a_2 = a;
    long long b_2 = b;
    if (a_2 / b_2 > std::numeric_limits<int>::max() or  a_2 / b_2 < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Overflow");
    }
    return a / b;
    
}