#include<bits/stdc++.h>
using namespace std;

//question 2
// Given a sorted array in which all elements appear twice (one after one) and one element appears only 
// once. Find that element in O(log n) complexity. 

/*
int check(vector<int> &v, int start, int end)
{
    if (start > end)
        return -1; 

    int mid = (start + end) / 2;

    if (mid % 2 == 0)
    {
        if (v[mid + 1] == v[mid])
            return check(v, mid + 2, end); 
        else if (v[mid - 1] == v[mid])
            return check(v, start, mid - 2); 
        else
            return v[mid]; 
    }
    else
    {
        if (v[mid] == v[mid - 1])
            return check(v, mid + 1, end); 
        else if (v[mid] == v[mid + 1])
            return check(v, start, mid - 1); 
        else
            return v[mid]; 
    }
}

int main()
{
    vector<int> v;
    int n;
    cout << "Enter the size: ";
    cin >> n;

    cout << "Enter the values: ";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        v.push_back(value);
    }

    int ans = check(v, 0, n - 1);
    cout << "Answer is => " << ans << endl;

    return 0;
}
*/

// Consider a sorted array A of n elements. The array A may have repetitive/duplicate elements. For a 
// given target element T, design and implement an efficient algorithm to find T’s first and last occurrence in 
// the array A. Also print the message if an element was not present in the array.

int main() {
 cout<<"enter the size of elements : ";
  int n;int k = 0;
  cin>>n;
  int arr[n];
  cout<<"enter the elements : ";
  for(int i=0;i<n;i++)
    cin>>arr[i];

  cout<<"enter target : ";
  int target;
  cin>>target;

  for(int i=0;i<n;i++)
    {  if(target == arr[i] && k == 0)                     
    {
      cout<<"target found at index "<<i<<endl;
      
      k++;
    }
     if(k>0 && arr[i] != target)
       cout<<"target last occur at :"<<i-1;
    }
}

