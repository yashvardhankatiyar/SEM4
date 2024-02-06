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

// quickSort
// int pivotFind(int arr[], int low, int high)
// {

//     int pivot = arr[high];
//     int i = (low - 1);

//     for (int j = low; j <= high; j++)
//     {
//         if (arr[j] < pivot)
//         {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     return (i + 1);
// }

// void quickSort(int arr[], int low, int high)
// {

//     if (low < high)
//     {

//         int pi = pivotFind(arr, low, high);

//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }

// int main()
// {
//     int arr[] = {10, 7, 8, 9, 1, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     quickSort(arr, 0, n - 1);

//     cout << "Sorted Array\n";
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

// l.)
/*
void mergeSortedHalves(int arr[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSortedArray(int arr[], int size)
{
    int mid = size / 2;
    mergeSortedHalves(arr, 0, mid - 1, size - 1);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 2, 4, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSortedArray(arr, size);

    std::cout << "Merged Sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
*/

// k.)

/*
void sortEO(vector<int> &arr)
{
    int n = arr.size();
    vector<int> even_places, odd_places;

    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            even_places.push_back(arr[i]);
        }
        else
        {
            odd_places.push_back(arr[i]);
        }
    }

    sort(even_places.begin(), even_places.end());

    sort(odd_places.begin(), odd_places.end(), greater<int>());

    int even_index = 0, odd_index = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            arr[i] = even_places[even_index++];
        }
        else
        {
            arr[i] = odd_places[odd_index++];
        }
    }
}

void print_array(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {5, 3, 8, 4, 2, 7, 1, 6};
    cout << "Original Array: ";
    print_array(arr);

    sortEO(arr);

    cout << "Modified Array: ";
    print_array(arr);

    return 0;
}
*/

// mergeSort

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
