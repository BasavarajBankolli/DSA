### C++

```cpp

#include <bits/stdc++.h>

using namespace std;

class Node {
    public: 
    int data;
    Node* next;

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

int main(){
    Node* x = new Node(2); // here x is variable and Node is datatype stored for that
    //Node* y = &x;      // if *isn't there infront of x then memory address of that x 

    cout << x->data << "\n";
    cout << x; // prints memory location of object that holds data as 2
}
  

```
### ouput
```
2                                               
0x227e5fd4b70  
```
