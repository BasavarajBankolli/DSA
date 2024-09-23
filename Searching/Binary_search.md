### C++
```cpp
#include <bits/stdc++.h>
using namespace std;

int binarySearch (vector<int> &arr, int x) {
    
    long n = arr.size();
    long left = 0;
    long right = n - 1;

    while (left <= right) {
        long mid = left + (right - left)/ 2;

        if (arr[mid] == x)
            return mid;

        else if (arr[mid] < x)
            left = mid + 1;

        else 
            right = mid - 1;
    }

    return - 1;
    
    
}

int main(){
    vector<int> arr = {1,5,7,10,13,15,24,40,51,67};
    int x = 40;
    cout << binarySearch(arr, x);

}
```

## output
```
arr = {1,5,7,10,13,15,24,40,51,67}
x = 40
---> 7

arr = {1,2,3,4,6,11,15,18,19}
x = 0
--->  -1

```
