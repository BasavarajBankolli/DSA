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
    vector <int> vec = {1,2,3,4};
    Node x = Node(2); // here x is variable and Node is datatype stored for that
    Node* y = &x;      // memory address of that x 

    cout << y->data;
}
  

```
