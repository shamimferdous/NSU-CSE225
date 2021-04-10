#include <iostream>
#include "stacktype.cpp"

using namespace std;

int main()
{
    int n, m, x, temp;
    cin >> n >> m >> x;

    //initing two stack obj
    StackType<int> A;
    StackType<int> B;

    //inserting items at stack A
    // cout << "Enter " << n << " values for Stack A: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp < 0)
        {
            cout << "Please enter a non-negative integer!" << endl;
            i = i - 1;
        }
        else
        {
            A.Push(temp);
        }
    }

    //inserting items at stack B
    // cout << "Enter " << m << " values for Stack B: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        if (temp < 0)
        {
            cout << "Please enter a non-negative integer!" << endl;
            i = i - 1;
        }
        else
        {
            B.Push(temp);
        }
    }

    // int sum = 0;
    // int score = 0;
    // while (sum <= x)
    // {

    //     //best bet will be to always try and pick
    //     //the integer that is small
    //     //to earn max possible score
    //     if (A.Top() < B.Top())
    //     {
    //         sum = sum + A.Top();
    //         A.Pop();
    //         score++;
    //     }
    //     else
    //     {
    //         sum = sum + B.Top();
    //         B.Pop();
    //         score++;
    //     }

    //     //this checks that after popping and adding the int to the sum
    //     //the sum exceeds x or not.
    //     //if x is exceeded it makes count, count-1
    //     if (!(sum <= x))
    //     {
    //         score = score - 1;
    //     }
    // }

    // cout << endl
    //      << score;

    int sum = 0;

    int ans = 0;

    while (1)
    {
        if (sum < x)
        {
            if (A.Top() <= B.Top())
            {
                sum += A.Top();
                if (sum <= x)
                {
                    A.Pop();
                    ans += 1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                sum += B.Top();
                if (sum <= x)
                {
                    B.Pop();
                    ans += 1;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
    cout << ans;
}