
### C++

```cpp

#include <bits/stdc++.h>
using namespace std;

vector<int> strStr(string s, string pat) {
    int m = pat.size(), n = s.size();
    vector<int> lps(m, 0);

    // Compute LPS array
    int prev = 0, i = 1;
    while (i < m) {
        if (pat[i] == pat[prev]) {
            lps[i] = prev + 1;
            prev++;
            i++;
        } else if (prev == 0) {
            lps[i] = 0;
            i++;
        } else {
            prev = lps[prev - 1];
        }
    }

    // Print LPS array (for debugging, similar to your Python code)
    /*
    for (int val : lps) {
        cout << val << " ";
    }
    cout << endl;
    */

    // KMP Pattern Matching
    vector<int> res;
    int j = 0;
    i = 0;
    
    while (i < n) {
        if (s[i] == pat[j]) {
            i++, j++;
        } else {
            if (j == 0) {
                i++;
            } else {
                j = lps[j - 1];
            }
        }

        if (j == m) {
            res.push_back(i - m);
            j = lps[j - 1];  // Move j using LPS to handle overlapping matches
        }
    }

    return res;
}

int main() {
    vector<int> res = strStr("AAAAAACAAAACAAAA", "AAACAAAA");

    for (int pos : res) {
        cout << pos << " ";
    }
    cout << endl;

    res = strStr("sadedsad", "sad");

    for (int pos : res) {
        cout << pos << " ";
    }
    cout << endl;

    res = strStr("baabaaba", "aaba");

    for (int pos : res) {
        cout << pos << " ";
    }
    cout << endl;


    return 0;
}

  

```
### ouput
```
3 8 
0 5
1 4
```
