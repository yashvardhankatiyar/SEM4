#include <bits/stdc++.h>
using namespace std;

bool find(vector<int> &v, int start, int end, int target)
{
    if (start >= end)
        return false;

    int mid = (start + end) / 2;

    if (target == v[mid])
        return true;
    else if (v[mid] == 0)
        return find(v, start, mid, target);
    else if (v[mid] > target)
        return find(v, start, mid, target);
    else if (v[mid] < target)
        return find(v, mid + 1, end, target);
}

int main()
{
    vector<int> v;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements : ";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        v.push_back(value);
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    if (find(v, 0, n, target))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}
