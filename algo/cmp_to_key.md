### C++
``` cpp
#include <bits/stdc++.h>
using namespace std;

// Custom comparator function
bool compare(const string &a, const string &b) {
    return a + b > b + a; // Compare concatenated results
}

string largestNumber(vector<int>& nums) {
    // Convert numbers to strings
    vector<string> ref;
    for (int num : nums) {
        ref.push_back(to_string(num));
    }

    // Sort using the custom comparator
    sort(ref.begin(), ref.end(), compare);

    // Handle edge case where the largest number is "0" (e.g., [0, 0])
    if (ref[0] == "0") {
        return "0";
    }

    // Concatenate the sorted strings
    string result;
    for (const string &s : ref) {
        result += s;
    }

    return result;
}

int main() {
    vector<int> nums = {3, 30, 34, 5, 9, 31};
    cout << "Largest number: " << largestNumber(nums) << endl;
    return 0;

}

int main() {
    vector<int> nums = {3, 30, 34, 5, 9, 31};
    cout << "Smallest number: " << smallestNumber(nums) << endl;
    return 0;
}
```
## O/p
```
Largest number: 953433130
```


### Python
``` python3
from functools import cmp_to_key

def largest(nums):

    def cmp(a,b):
        if a+b > b+a: # 31 + 3 > 3 + 31
            return -1
        return a+b < b+a # 31+3 < 3+31

    ref = [str(v) for v in nums]
    ref.sort(key=cmp_to_key(cmp))

    return "".join(ref)


if "__main__" == __name__:
    print(largest([3,30,34,5,9,31]))
```

## O/p
```
953433130
```


