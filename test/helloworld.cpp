#include <iostream>
using namespace std;

int main()
{
    int i;
    cin >> i;
    int * mypointer = &i;

    cout << mypointer << endl;
}