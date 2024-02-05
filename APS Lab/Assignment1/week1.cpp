#include <bits/stdc++.h>
using namespace std;

// Sort the entire array using selection sort, bubble sort, insertion sort, quick sort and merge
// sort. Print the total number of comparisons done in each of the sorting algorithm.

// selection sort

vector<int> selectionSort(vector<int> &v)
{
    int min;

    for (int i = 0; i < v.size() - 1; i++)
    {
        min = v[0];
        for (int j = i + 1; j++; j < v.size())
        {
            if (v[j] < min)
                swap(v[j], min);
        }
    }

    return v;
}

int main()
{
    vector<int> v = {3, 5, 7, 3, 2, 1, 9, 8};
    
    //selection sort
    v = selectionSort(v);
    for(auto i: v)
        cout<<i<<" ";
}