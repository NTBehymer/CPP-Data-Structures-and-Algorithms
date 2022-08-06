#include <iostream>

void Square(int a){ // This function will do nothing to the original variable, as it is local and cannot be modified outside the function
    a = a * a;
    std::cout << "Memory address of variable in 'Square': " << &a << "\n";
    }

void PtrSquare(int* p){
    *p = (*p) * (*p);
    std::cout << "Memory address of variable in 'PtrSquare': " << p << "\n";
}

int main(){
    int a = 5; // "a" is a local variable, cannot be changed out side of the function
    std::cout << "Memory address of variable in 'main': " << &a << "\n"; // Memory addresses of "a" in main and "a" in Square will be different, as they are local
    Square(a); // Square doesn't return anything so, "a" will remain the same
    std::cout << "Value of variable in main after calling 'Square': " << a << '\n'; // Prints out the value of "a" still without squaring it
    int* p = &a;
    PtrSquare(p);
    std::cout << "Value of variable in main after calling 'PtrSquare': " << a << '\n';
}