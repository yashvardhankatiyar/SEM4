#include <bits/stdc++.h>
using namespace std;

// question 2
//  Given a sorted array in which all elements appear twice (one after one) and one element appears only
//  once. Find that element in O(log n) complexity.

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

// question 5
// Consider a sorted array A of n elements. The array A may have repetitive/duplicate elements. For a
// given target element T, design and implement an efficient algorithm to find T’s first and last occurrence in
// the array A. Also print the message if an element was not present in the array.

/*
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
*/

// question 3
// List of points have been given on 2D Plane. Calculate K closest points to the origin (0,0) (Consider
// euclidean distance to find the distance between two points). Write a code to return the answer in any order.
// The solution is guaranteed to be unique.

/*
struct Point {
    int x, y;
    double distance;
};

struct CompareDistance {
    bool operator()(const Point& p1, const Point& p2) {
        return p1.distance > p2.distance;
    }
};

void push_heap(vector<Point>& heap, const Point& newPoint) {
    heap.push_back(newPoint);
    int currentIndex = heap.size() - 1;
    while (currentIndex > 0) {
        int parentIndex = (currentIndex - 1) / 2;
        if (heap[parentIndex].distance > heap[currentIndex].distance) {
            swap(heap[parentIndex], heap[currentIndex]);
            currentIndex = parentIndex;
        } else {
            break;
        }
    }
}

void pop_heap(vector<Point>& heap) {
    if (heap.empty()) return;
    heap[0] = heap.back();
    heap.pop_back();
    int currentIndex = 0;
    while (true) {
        int leftChild = 2 * currentIndex + 1;
        int rightChild = 2 * currentIndex + 2;
        int smallestIndex = currentIndex;
        if (leftChild < heap.size() && heap[leftChild].distance < heap[smallestIndex].distance) {
            smallestIndex = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild].distance < heap[smallestIndex].distance) {
            smallestIndex = rightChild;
        }
        if (smallestIndex != currentIndex) {
            swap(heap[currentIndex], heap[smallestIndex]);
            currentIndex = smallestIndex;
        } else {
            break;
        }
    }
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    vector<Point> heap;

    for (const auto& point : points) {
        Point newPoint;
        newPoint.x = point[0];
        newPoint.y = point[1];
        newPoint.distance = sqrt(newPoint.x * newPoint.x + newPoint.y * newPoint.y);
        push_heap(heap, newPoint);
        if (heap.size() > K) {
            pop_heap(heap);
        }
    }

    vector<vector<int>> result;
    for (const auto& point : heap) {
        result.push_back({point.x, point.y});
    }

    return result;
}

int main() {
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int K = 2;

    vector<vector<int>> closestPoints = kClosest(points, K);

    cout << "K closest points to the origin: ";
    for (const auto& point : closestPoints) {
        cout << "(" << point[0] << ", " << point[1] << ") ";
    }
    cout << endl;

    return 0;
}

*/

// question 4

// Let there be an array of N random elements. We need to sort this array in ascending order. If n is very 
// large (i.e. N= 1,00,000) then Quicksort may be considered as the fastest algorithm to sort this array. 
// However, we can further optimize its performance by hybridizing it with insertion sort. Therefore, if n is 
// small (i.e. N<= 10) then we apply insertion sort to the array otherwise Quick Sort is applied. Implement the 
// above discussed hybridized Quick Sort and compare the running time of normal Quick sort and hybridized 
// quick sort. Run each type of sorting 10 times on a random set of inputs and compare the average time 
// returned by these algorithms.

/*
using namespace chrono;

void insertion_sort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort_hybridized(vector<int>& arr, int low, int high, int k) {
    while (low < high) {
        if (high - low + 1 <= k) {
            insertion_sort(arr, low, high);
            break;
        } else {
            int pivotIndex = partition(arr, low, high);
            if (pivotIndex - low < high - pivotIndex) {
                quick_sort_hybridized(arr, low, pivotIndex - 1, k);
                low = pivotIndex + 1;
            } else {
                quick_sort_hybridized(arr, pivotIndex + 1, high, k);
                high = pivotIndex - 1;
            }
        }
    }
}

void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quick_sort(arr, low, pivotIndex - 1);
        quick_sort(arr, pivotIndex + 1, high);
    }
}

double run_sorting_algorithm(vector<int>& arr, int k, void (*sorting_algorithm)(vector<int>&, int, int)) {
    auto start = high_resolution_clock::now();
    sorting_algorithm(arr, 0, arr.size() - 1, k);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

int main() {
    srand(time(0));

    const int N = 100000;
    const int num_trials = 10;

    vector<int> regular_quick_sort_times(num_trials);
    vector<int> hybrid_quick_sort_times(num_trials);

    for (int trial = 0; trial < num_trials; ++trial) {
        vector<int> arr(N);
        generate(arr.begin(), arr.end(), rand);

        vector<int> arr_copy = arr;

        // Regular Quick Sort
        regular_quick_sort_times[trial] = run_sorting_algorithm(arr, 0, quick_sort);

        // Hybridized Quick Sort with Insertion Sort (set k as 10)
        hybrid_quick_sort_times[trial] = run_sorting_algorithm(arr_copy, 10, quick_sort_hybridized);
    }

    double regular_quick_sort_average = accumulate(regular_quick_sort_times.begin(), regular_quick_sort_times.end(), 0.0) / num_trials;
    double hybrid_quick_sort_average = accumulate(hybrid_quick_sort_times.begin(), hybrid_quick_sort_times.end(), 0.0) / num_trials;

    cout << "Average time for regular Quick Sort: " << regular_quick_sort_average << " microseconds" << endl;
    cout << "Average time for hybridized Quick Sort: " << hybrid_quick_sort_average << " microseconds" << endl;

    return 0;
}
*/

//question 1.
// Cubic integer root x of n is largest number x such that x3<=n. Find the value of x given n using divide 
// and conquer approach. Also analyze the complexity.

/*

long long int cubic_root(long long int n) {
    long long int low = 0;
    long long int high = n;

    while (low <= high) {
        long long int mid = low + (high - low) / 2;
        long long int mid_cubed = mid * mid * mid;

        if (mid_cubed == n) {
            return mid;
        } else if (mid_cubed < n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return high; 
}

int main() {
    long long int n;
    cout << "Enter a number : ";
    cin >> n;

    long long int result = cubic_root(n);
    cout <<"answer => "<< result << endl;

    return 0;
}

*/