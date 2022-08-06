#include <iostream>
#include <stdlib.h>

int* heapCreation(){
    int* p = new int(10); // When using the 'new' keyword (or malloc in C) it stores the variable on the heap (free memory)
    return p;
}

int* stackCreation(){
    int a = 5; // Local variables are allocated on the stack, and deleted automatically when the function is terminated
    return &a;
}

int main() {
    int* a = stackCreation();
    int* p = heapCreation();
    std::cout << "Printing stack variable 'a' from main: " << *a << '\n'; // Will print a garbage value because it is stored in the stack as a local variable
    // and is cleared once it's function is finished
    std::cout << "Printing heap variable 'p' from main: " << *p << '\n'; // The variable stored will persist until it is freed from the heap with
    // the delete keyword (or free in C after using malloc)
    delete(p); // Anything stored on the heap must be freed from the heap's memeory, or else it can stay there and create memeory leaks
}