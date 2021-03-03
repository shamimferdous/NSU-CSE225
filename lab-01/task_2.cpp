// Task 2: Using the new operator, allocate a two dimensional character array. Again the number of rows and columns
// are going to be provided by the user as input. All of the rows are the same size. Take character strings as input from
// the user and then print the strings. Finally de-allocate the array using the delete operator.

#include <iostream>

using namespace std;

int main()
{

    int row, col;
    //getting size of row and col from user
    cout << "Enter size of row and col respectively: ";
    cin >> row >> col;

    //allocating memory
    char **arr = new char *[row]; //char arr of size row
    for (int i = 0; i < row; i++)
    { //initing mem for col of each row
        arr[i] = new char[col];
    }

    //getting input from user
    for (int foo = 0; foo < row; foo++)
    {
        for (int bar = 0; bar < col; bar++)
        {
            cout << "Enter array element at index [" << foo << ", " << bar << "]: ";
            cin >> arr[foo][bar];
        }
    }

    //console logging the two dm array
    cout << endl;
    for (int foo = 0; foo < row; foo++)
    {
        for (int bar = 0; bar < col; bar++)
        {
            // cout << "Array element at index [" << foo << ", " << bar << "]: " << arr[foo][bar] << endl;
            cout << arr[foo][bar]; //this way the chars will take shape as word
        }
        cout << endl;
    }

    //deallocating memory
    delete[] arr;
}