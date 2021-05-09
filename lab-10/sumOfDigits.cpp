#include <iostream>

using namespace std;

int sumOfDigits(int x)
{
    if (x == 0)
    {
        return 0;
    }
    else
    {
        return (x % 10 + sumOfDigits(x / 10));
    }
}

int main()
{
    int input;
    cout << "Enter a number: ";
    cin >> input;

    cout << sumOfDigits(input) << endl;
}