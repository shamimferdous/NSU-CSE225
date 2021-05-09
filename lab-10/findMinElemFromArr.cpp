#include <iostream>

using namespace std;

int findMin(int a[], int size)
{
    if (size == 1)
    {
        return a[0]; //if there's only 1 elem in the arr
    }
    else
    {
        int minimum = findMin(a, size - 1);

        if (minimum < a[size - 1])
        {
            return minimum;
        }
        else
        {
            return a[size - 1];
        }
    }
}

int main()
{
    int temp;
    int arr[5];
    cout << "Enter 5 integers respectively: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }

    cout << "Min Element: " << findMin(arr, (sizeof(arr) / sizeof(arr[0])));

    return 0;
}