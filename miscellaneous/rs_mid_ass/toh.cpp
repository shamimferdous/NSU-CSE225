#include <iostream>
using namespace std;

void towerOfHanoi(int n, char rod_A,
                  char rod_B, char rod_C)
{
    if (n == 1)
    {
        cout << "Move disk #1 from rod " << rod_A << " to rod " << rod_B << endl;
        return;
    }
    towerOfHanoi(n - 1, rod_A, rod_C, rod_B);
    cout << "Move disk #" << n << " from rod " << rod_A << " to rod " << rod_B << endl;
    towerOfHanoi(n - 1, rod_C, rod_B, rod_A);
}

int main()
{
    int number_of_discs = 5;
    towerOfHanoi(number_of_discs, 'A', 'C', 'B');
    return 0;
}
