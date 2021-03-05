// Task 3: Modify the header file and the source files again, so that it works for two dimensional array where all the
// rows are the same size. The user will specify the number of rows and columns as well as the content of the array,
// which you will take as input from user in the main function.

#include <iostream>
#include "dynarr.h"
#include "dynarr.cpp"

using namespace std;

int main()
{
    int row, col;

    cout << "Enter row size and col size respectively: " << endl;
    cin >> row >> col;

    // create 2d dynArr obj
    dynArr twoDArr(row, col);

    //getting input from user and storing in twoDArr using the set method
    int temp;
    for (int foo = 0; foo < row; foo++)
    {
        for (int bar = 0; bar < col; bar++)
        {
            cout << "Enter array element at index [" << foo << ", " << bar << "]: ";
            cin >> temp;
            twoDArr.setValue(foo, bar, temp);
        }
    }

    //console logging the two d arr
    cout << endl;
    for (int foo = 0; foo < row; foo++)
    {
        for (int bar = 0; bar < col; bar++)
        {
            cout << "Array element at index [" << foo << ", " << bar << "]: " << twoDArr.getValue(foo, bar) << endl;
        }
    }
}