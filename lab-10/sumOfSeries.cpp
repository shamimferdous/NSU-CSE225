#include <iostream>
#include <cmath>

using namespace std;

double findSum(int n)
{

    if (n == 0)
    {
        return 1;
    }
    else
    {
        return ((1.0 / pow(2, n)) + findSum(n - 1));
    }
}

int main()
{
    int input;
    cout << "Enter n: ";
    cin >> input;

    cout << "Sum: " << findSum(input);

    return 0;
}