### C++
```cpp
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int left = low + 1;
    int right = high;
    int pivotValue = arr[low];
    
    bool done = true;
    while (done) {
        while (left <= right && arr[left] <= pivotValue) {
            left++;
        }
        
        while (right >= left && arr[right] >= pivotValue) {
            right--;
        }
        
        if (right < left) {
            done = false;
        } else {
            swap(arr[left], arr[right]);
        }
    }
    
    arr[low] = arr[right];
    arr[right] = pivotValue;
    return right;
}

void quick(vector<int>& arr, int low, int high) {
    if (low < high) {
        int splitPoint = partition(arr, low, high);
        quick(arr, low, splitPoint - 1);
        quick(arr, splitPoint + 1, high);
    }
}

int main() {
    vector<int> arr = {2, 3, 6, 1, 5};
    quick(arr, 0, arr.size() - 1);
    
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

```
## Output
```
1 2 3 5 6
```
