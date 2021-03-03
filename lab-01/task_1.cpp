// Task 1: Using the new operator, allocate an integer array of user specified size (the user gives the size of the array as
// input). Assign values to the array elements by taking user inputs and then print the values. Finally de-allocate the array
// using the delete operator.

#include <iostream>

using namespace std;

int main()
{
    int size;

    //getting size from user
    cout << "Enter array size: ";
    cin >> size;

    //allocating array
    int *arr = new int[size];

    //getting input from user
    for (int i = 0; i < size; i++)
    {
        cout << "Enter array element at index " << i << " :";
        cin >> arr[i];
    }

    //console loggin the arr
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Array element at index " << i << " : " << arr[i] << endl;
    }

    //deallocating memory
    delete arr;

    return 0;
}