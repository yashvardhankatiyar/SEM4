#include <bits/stdc++.h>
using namespace std;

// Propose and implement a divide and conquer based algorithm to compute XY.
// Input to your program are X and Y and output of your program is XY.

int solve(int x, int y)
{
    if (y == 0)
        return 1;

    if (y == 1)
        return x;

    if (y % 2 == 0)
    {
        int temp = solve(x, y / 2);
        return temp * temp;
    }
    else
    {
        int temp = solve(x, (y - 1) / 2);
        return x * temp * temp;
    }
}

int main()
{
    cout << "enter the value of x and y : ";
    int x, y;
    cin >> x >> y;

    int ans = solve(x, y);
    cout << "Answer => " << ans;
}