// Task 3: Ask user for two integers, 𝑎𝑎 and 𝑏𝑏. Then swap (interchange) the values of 𝑎𝑎 and 𝑏𝑏.
// That means, 𝑎𝑎 should get the value of 𝑏𝑏 and 𝑏𝑏 should get the value of 𝑎𝑎.

#include <iostream>

using namespace std;

int main()
{
    int a, b, temp;

    cout << "Enter two integer respectively: " << endl; //getting user input
    cin >> a >> b;

    //swapping
    temp = a;
    a = b;
    b = temp;

    cout << "Value of a and b respectively: " << a << ", " << b << endl;

    return 0;
}