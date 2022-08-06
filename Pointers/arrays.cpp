#include <iostream>

int SizeOfArray(int a[]){ // When calling arrays in functions, it only points to the first item (So int a[] is the same thing as int* a)
    int size = sizeof(a);
    return size;
}

void print(char* c){ // This "print" function will iterate through the array and print out each character until it finds the escape null character located at the end of strings
    int i = 0;
    while (c[i] != '\0'){
        std::cout << c[i];
        i++;
    }
    std::cout << '\n';
}

int main(){
    int a[] = {1,2,3,4,5};
    std::cout << "Size of array in main: " << sizeof(a) << "\n"; // Size will be the size of the variable type times the size of the array
    int soa = SizeOfArray(a); // Passing "a" into the function is esentially the same as passing &a[0]
    std::cout << "Size of array in SizeOfArray: " << soa << "\n"; // Size will only be the size of a single variable. So in this example 4 bytes, the size of an int.

    char c1[] = "Nathan";
    char* c2;
    c2 = c1;
    *c2 = 'B'; // c2 is just a pointer the beginning of the char array
    std::cout << c1 << '\n';
    c2++; // Incrementing the pointer to the next char in the char array
    *c2 = 'e';
    std::cout << c1 << '\n';
    c2--;
    print(c1);
    print(c2); // Either of these work as calling the array is the same as calling a pointer to the beginning

}