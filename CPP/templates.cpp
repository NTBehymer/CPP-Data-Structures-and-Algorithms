#include <iostream>

// Templates are not "real" C++, they generate the code during compile when the need arises
template <typename T> // Create a template type here and define it as "T"
T maximum(T a, T b){ // Create a function as normal but use the "T" type instead of int, double, char, etc.
    return (a > b) ? a : b;
} // All instances of "T" must be the same during one call to the function
  // Unless, you specifically typecast it when calling, as shown later in this file.

int main() {
    int a = 3;
    int b = 7;

    double c = 3.14;
    double d = 5.67;

    int* p_a = &a;
    int* p_b = &b;

    auto resultInt = maximum(a, b); // Compiler creates an int version of maximum
    auto resultDouble = maximum(c, d); // Compiler creates a double version of maximum
    auto resultPointer = maximum(p_a, p_b); // Compiler creates a pointer version of maximum. Will output the higher MEMORY value, not int value.
    double resultIntDouble = maximum<double>(a, c); // Typecasting a template will convert all instances of "T" in the function to the typecast, if possible. Otherwise it will error out

    std::cout << "Maximum of int: " << resultInt << "\n";
    std::cout << "Maximum of double: " << resultDouble << "\n";
    std::cout << "Maximum of pointer address: " << resultPointer << "\n";
    std::cout << "Maximum of and Int and Double: " << resultIntDouble << "\n";
    
    return 0;
}