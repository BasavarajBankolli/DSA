### C++

```cpp
#include <bits/stdc++.h>
using namespace std;

int linearSearch (vector<int> &arr, int x) {
    
    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] == x)
            return i;
    
    }

    return -1;

}

int main(){
    vector<int> arr = {2,7,5,3,2,9,1};
    int x = 2;
    cout << linearSearch(arr, x);

}
```

## output
```
6
```
