// Task 2: Modify the header and the source files. Add a member function void allocate(int s) which allows
// you to change the size of the array. Make sure that memory is not leaked.

#include <iostream>
#include "dynarr.h"
#include "dynarr.cpp"

using namespace std;

int main()
{
    //creating dynArr obj with both constructor
    dynArr arrOne();
    dynArr arrTwo(5); //current arr size is 5

    //changign the size of the arr
    int tempSize;
    cout << "Current size of array is 5, Enter an integer to change it: ";
    cin >> tempSize;
    arrTwo.allocate(tempSize);

    //getting values from user and storing
    //inside arrTwo obj the using set method
    int temp;
    for (int i = 0; i < tempSize; i++)
    {
        cout << "Enter a value: ";
        cin >> temp;
        arrTwo.setValue(i, temp);
    }

    //printing the values
    cout << endl;
    for (int i = 0; i < tempSize; i++)
    {
        cout << arrTwo.getValue(i) << endl;
    }
}