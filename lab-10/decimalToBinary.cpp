#include <iostream>

using namespace std;

int DecToBin(int dec)
{
    if (dec == 0)
    {
        return 0;
    }
    else
    {
        return (dec % 2 + 10 * DecToBin(dec / 2));
    }
}

int main()
{
    int input;
    cout << "Enter a decimal number: ";
    cin >> input;

    cout << DecToBin(input) << endl;

    return 0;
}