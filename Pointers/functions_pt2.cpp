#include <iostream>
#include <math.h>

int Add(int a, int b){
    return a+b;
}

int compare(int a, int b){
    if (a > b) return 1;
    else return -1;
}

int absoluteCompare (int a, int b){
    if (abs(a) > abs(b)) return 1;
    else return -1;
}

void BubbleSort(int A[], int n, int (*compare)(int, int)){
    int i,j,temp;
    for (i = 0; i<n; i++){
        for (j=0; j<n-1; j++){
            if (compare(A[j], A[j+1]) > 0){ // Compares A[j] and A[j+1] and swaps if needed
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main(){
    int (*p)(int, int); // The parenthesis around the '*p' declare it is a function pointer
    p = &Add;
    std::cout << p << '\n';
    int c = (*p)(2,3); // Derefrences the function pointer and executes it with the passed variables
    std::cout << c << '\n'; // Will print the 2 numbers passed above added together

    int A[] = {3,2,-1,-5,9,-7};
    BubbleSort(A, 6, compare);
    for(int i=0;i<6;i++) std::cout << A[i] << ' ';
    std::cout << '\n';

    BubbleSort(A, 6, absoluteCompare);
    for(int i=0;i<6;i++) std::cout << A[i] << ' ';
    std::cout << '\n';
}