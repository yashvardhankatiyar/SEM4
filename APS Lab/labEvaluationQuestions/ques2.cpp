#include <iostream>
using namespace std;

int factorial(int N)
{
    if (N == 0 || N == 1)
    {
        return 1;
    }
    else
    {

        int mid = N / 2;
        int firstPart = factorial(mid);
        int secondPart = 1;

        for (int i = mid + 1; i <= N; ++i)
        {
            secondPart *= i;
        }

        return firstPart * secondPart;
    }
}

int main()
{
    int n;
    cout << "Enter a integer : ";
    cin >> n;

    int result = factorial(n);
    cout << "answer => " << result << endl;

    return 0;
}
