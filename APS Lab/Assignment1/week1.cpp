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
        min = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[min])
                min = j;
        }

        swap(v[i], v[min]);
    }

    return v;
}

// insertion sort
vector<int> insertionSort(vector<int> &v)
{
    int n = v.size();

    for (int i = 1; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }

    return v;
}

// bubbleSort
vector<int> bubbleSort(vector<int> v)
{
    int n = v.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }

    return v;
}

int main()
{
    vector<int> v = {3, 5, 7, 3, 2, 1, 9, -12, 8675, 8};

    // selection sort
    v = selectionSort(v);
    for (auto i : v)
        cout << i << " ";

    // insertion sort
    v = insertionSort(v);
    for (auto i : v)
        cout << i << " ";

    // bubble sort
    v = bubbleSort(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
}