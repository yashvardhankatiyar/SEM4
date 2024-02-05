//  Given a sorted array of n elements containing only two distinct integers x
// and y, design an algorithm to find the transition point efficiently. The transition point is
// the point where x ends and y begins. You are required to first take x, y and the array size
// and the number of occurrences of x as input and then create the array before passing it to
// the desired algorithm. Deduce the complexity of your algorithm with proper logic.

#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &v, int start, int end, int x, int y)
{
    if (start == end)
        return start;

    int mid = (start + end) / 2;

    if (v[mid] == x)
        find(v, mid + 1, end, x, y);
    else
        find(v, start, mid, x, y);
}

int main()
{
    vector<int> v;
    int n;
    cout << "enter the number of elements : ";
    cin >> n;

    cout << "enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        v.push_back(value);
    }

    int x, y;
    cout << "enter the distinct elements : ";
    cin >> x >> y;

    int point = find(v, 0, n - 1, x, y);
    cout << "Points => " << point << endl;
}