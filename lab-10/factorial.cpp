#include <iostream>

using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int input;
    cout << "Enter a number: ";
    cin >> input;

    cout << factorial(input) << endl;

    return 0;
}