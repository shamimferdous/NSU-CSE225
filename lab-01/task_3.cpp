// Task 3: Using the new operator, allocate a two dimensional integer array. The number of rows and columns are going
// to be provided by the user as input. However, in this task, all of the rows are not the same size (the array is uneven).
// The user will specify how many elements the individual rows will have. Assign values to the array elements by taking
// user inputs and then print the values. Finally de-allocate the array using the delete operator.

#include <iostream>

using namespace std;

int main()
{
    int row;
    //getting size of row from user
    cout << "Enter size of row: ";
    cin >> row;

    //allocating memory
    int **arr = new int *[row]; //int arr of size row
    int colSizeStorage[row];    //this arr will store the size of col of each row. for iteration purpose
    for (int i = 0; i < row; i++)
    {
        //getting size of col for each row and allocating mem for the col of each row
        int col;
        cout << "Enter col size for row " << arr[i] << ": ";
        cin >> col;
        arr[i] = new int[col];
        //storing the col size in the colSizeStorage arr
        colSizeStorage[i] = col;
    }

    //getting input from user
    for (int foo = 0; foo < row; foo++)
    {
        for (int bar = 0; bar < colSizeStorage[foo]; bar++)
        {
            cout << "Enter array element at index [" << foo << ", " << bar << "]: ";
            cin >> arr[foo][bar];
        }
    }

    //console logging the arr
    cout << endl;
    for (int foo = 0; foo < row; foo++)
    {
        for (int bar = 0; bar < colSizeStorage[foo]; bar++)
        {
            cout << "Array element at index [" << foo << ", " << bar << "]: " << arr[foo][bar] << endl;
        }
    }

    //deallocating memory
    delete[] arr;

    return 0;
}