#include <iostream>

// Reading the declerations backwards can help with understanding them. Ex) int[]** would be: a pointer to a pointer to an array of integers
int main() {
    short a;
    short *p; // Creates a pointer to a variable

    a = 5;
    p = &a; // Sets the value of the pointer to the address of a variable

    std::cout << "Address the pointer points to: " << p << "\n"; // Print out the address of the pointer
    std::cout << "Address of variable: " << &a << "\n"; // Prints out the address of a variable (will be the same as above)
    std::cout<< "Value held by the address the pointer points to: " << *p << "\n"; // Print out the value of the address the pointer points to

    *p = 7; // Changes the value at the address the pointer points to

    std::cout << "Value at address pointer holds after change: " << *p << "\n";

    std::cout << "Address pointer points to after adding 1 to address: " << p + 1 << "\n"; // After adding 1 to the address the pointer holds, it should be 2 bytes greater because
    // it holds a short, and shorts are 2 bytes in length

    short **pp; // Creates a pointer to a pointer
    pp = &p; // Sets the value of the "pointer to a pointer" to the address of another pointer
    std::cout << "Value the address a pointer to a poiter holds: " << **pp << "\n";
}