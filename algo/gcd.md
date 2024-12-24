
### C++

```cpp

#include <bits/stdc++.h>

using namespace std;

int gcd(int &a, int &b){   // Euclidean algo for gcd(8, 10)
    while (b != 0){      // 10, 8, 2
        int temp = b;    // 10, 8, 2
        b = a % b;       // 8, 2, 0
        a = temp;        // 10, 8, 2 and b == 0 exit from loop
    }
    return a;
}

int main () {
    int a = 4;
    int b = 8;
    cout << gcd(a, b) << "\n";

    a = 8;
    b = 10;
    cout << gcd(a,b); 

    return 0;
}
  

```
### ouput
```
4
2
```
