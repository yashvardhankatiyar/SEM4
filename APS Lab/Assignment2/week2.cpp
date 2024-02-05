#include <bits/stdc++.h>
using namespace std;

//  question 1:
//  You are given an array A[m] where first n cells contain integers in sorted order and the rest of the cells
//  are filled with 0. Here assumes m>>n and value of n is unknown. Implement an algorithm that takes
//  an integer x as input and finds a position in the array containing x, if such a position exists, in O (log
//  n) time.

/*
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
*/

// question 2
// Assume that we are given n pairs of items as input, where the first item is a number and the second
// item is one of three colours (red, blue, or yellow). Further assume that the items are sorted by number.
// Give an O(n) algorithm to sort the items by colour (all reds before all blues before all yellows) such
// that the numbers for identical colours stay sorted. For example: (1, blue), (3, red), (4, blue), (6, yellow),
// (9, red) should become (3, red), (9, red), (1, blue), (4, blue), (6, yellow).

/*
vector<pair<int, string>> change(vector<pair<int, string>> &v)
{
    queue<pair<int, string>> red, yellow, blue;
    vector<pair<int, string>> ans;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second == "red")
            red.push({v[i].first, v[i].second});
        else if (v[i].second == "yellow")
            yellow.push({v[i].first, v[i].second});
        else if (v[i].second == "blue")
            blue.push({v[i].first, v[i].second});
    }

    while (!red.empty())
    {
        ans.push_back({red.front().first, red.front().second});
        red.pop();
    }
    while (!yellow.empty())
    {
        ans.push_back({yellow.front().first, yellow.front().second});
        yellow.pop();
    }
    while (!blue.empty())
    {
        ans.push_back({blue.front().first, blue.front().second});
        blue.pop();
    }

    return ans;
}

int main()
{
    vector<pair<int, string>> v;
    int n;
    cout << "Enter number of pairs : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int value1;
        cout << "enter number for " << i + 1 << "th pair : ";
        cin >> value1;
        string value2;
        cout << "enter color(blue, yellow, red) for " << i + 1 << "th pair : ";
        cin >> value2;

        v.push_back({value1, value2});
    }

    v = change(v);

    for (auto i : v)
    {
        cout << i.first << " - " << i.second << endl;
    }

    return 0;
}
*/

// question 4A
// Implement the recursive algorithms for (a) Tower of Hanoi and (b) Fibonacci Number computation 
// and analyse the space and time requirements of both the algorithms. 

/*
void TowerOfHanoi(int start, int end, char diskA, char diskB, char diskC)
{
    if(start > end)
        return;
    
    TowerOfHanoi(start, end-1, diskA, diskC, diskB);
    cout<<"move disk "<<end<<" from "<<diskA<<" to "<<diskC<<endl;
    TowerOfHanoi(start, end-1, diskB, diskA, diskC);
}

int main()
{
    cout<<"enter the number of disks : ";
    int n;
    cin>>n;
    char diskA = 'A', diskB = 'B', diskC = 'C';

    TowerOfHanoi(1,n, diskA, diskB, diskC);
}
*/

//question 4B
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter the value of n for Fibonacci series : ";
    cin >> n;

    cout<<" => ";
    for (int i = 0; i < n; ++i) {
        cout << fibonacci(i) << " ";
    }

    return 0;
}


