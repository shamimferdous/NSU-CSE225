// Task 5: Write a program to read an integer amount and break the amount into smallest possible number of bank notes.

// Sample input:
// Input the amount: 375

// Sample output:
// There are:
// 3 note(s) of 100.00
// 1 note(s) of 50.00
// 1 note(s) of 20.00
// 0 note(s) of 10.00
// 1 note(s) of 5.00
// 0 note(s) of 2.00
// 0 note(s) of 1.00

#include <iostream>

using namespace std;

int main()
{
    int amount;

    cout << "Enter amount: " << endl;
    cin >> amount;

    cout << int(amount / 100) << " note(s) of 100.00" << endl;
    amount = amount - (100 * int(amount / 100));

    cout << int(amount / 50) << " note(s) of 50.00" << endl;
    amount = amount - (50 * int(amount / 50));

    cout << int(amount / 20) << " note(s) of 20.00" << endl;
    amount = amount - (20 * int(amount / 20));

    cout << int(amount / 10) << " note(s) of 10.00" << endl;
    amount = amount - (10 * int(amount / 10));

    cout << int(amount / 5) << " note(s) of 5.00" << endl;
    amount = amount - (5 * int(amount / 5));

    cout << int(amount / 2) << " note(s) of 2.00" << endl;
    amount = amount - (2 * int(amount / 2));

    cout << int(amount / 1) << " note(s) of 1.00" << endl;
    amount = amount - (1 * int(amount / 1));

    return 0;
}
