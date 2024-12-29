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

// 1.convert Vactro to LL
Node* convertVec(vector<int> &vec){
    if (vec.empty()) return nullptr;

    Node* head = new Node(vec[0]);
    Node* mover = head;

    for (int i = 1; i < vec.size(); i++) {
        Node* temp = new Node(vec[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

// 2.calculate lenght of LL
int lengthLL (Node* head) {
    int cnt = 0;
    
    Node* temp = head;

    while (temp) {
        cnt ++;
        temp = temp -> next;
    }

    return cnt;
}

// 3.check weather given element is exist in LL 
bool exist(Node* head, int x){
    Node* temp = head;

    while(temp){
        if (temp -> data == x){
            return true;
        }
        temp = temp -> next;
    }
    return false;

}

// 4.delete head of the LL
Node* removehead(Node* head){
    if (head == NULL) return head; 
    
    Node* temp = head;

    head = head -> next;
    delete temp; //free(temp); 
    return head;

}

// 5.delete tail of LL
Node* removetail(Node* head){
    Node* temp = head;
    
    //Handle single-node linked lists
    if (!head || !head->next) {
        delete head;
        return nullptr;
    }

    while(temp -> next -> next){
        temp = temp -> next;
    }

    delete temp -> next;
    temp -> next = nullptr;
    return head;
}


// 6.delete kth node from LL
Node* delKth(Node* head, int k){

    if (head == NULL) return head; 

    if (k == 1) { 
        Node* temp = head;        
        head = head->next;         
        delete(temp);       // for memory deallocation..         
        return head;               
    }

    int cnt = 0;
    Node* dummy = head;
    Node* prev = nullptr;

    while (dummy) {
        if (cnt == k){
            if (dummy -> next){
                prev -> next = dummy -> next;
            }
            else {
                prev -> next = nullptr;
            } 
            delete(dummy);
            break;
        }
        prev = dummy;
        dummy = dummy -> next;   
        cnt++;
    }
    return head;
}

// 7.delete node of given element from LL
Node* delEle(Node* head, int ele){

    if (head == NULL) return head;

    if (head -> data == ele) {
    Node* temp = head;
    head = head -> next;
    delete(temp);
    return head;
    }

    Node* dummy = head;
    Node* prev = NULL;

    while (dummy != NULL) {
        if ( dummy -> data == ele){
            // Safeguard check for prev->next
            if (prev != NULL) {
                prev -> next = dummy -> next;
            }
            delete (dummy);
            return head;
        }
        prev = dummy;
        dummy = dummy -> next;   

    }
    return head;
}

// 8.insert new Node to front of LL(head of LL)
Node* insertFront(Node* head, int v) {
    Node* temp = new Node(v);
    temp -> next = head;
    return temp;
    
}

// 9.insert new Node to rear of LL(tail of LL)
Node* insetRear(Node* head, int v) {
    Node* temp = new Node(v);
    
    if (head == NULL) return temp;
    
    Node* dummy = head;
    while (dummy -> next) {
        dummy = dummy -> next;
    }

    dummy -> next = temp;

    return head;
}

// 10.insert a node at given position with given element..
Node* inertK(Node* head, int posi, int v) {
    if (head == NULL) {
        if (posi == 1){
            return new Node(v);
        }
        else return head;
    }
    
    Node* temp = new Node(v);

    if (posi == 1) {
        temp -> next = head;
        return temp;
    }

    int cnt = 0;
    Node* dummy = head;

    while (dummy) {
        cnt++;
        
        if (cnt == (posi - 1)) {
            temp -> next = dummy -> next;
            dummy -> next = temp;
            break;
        }

        dummy = dummy -> next;
    }
    return head;

}

// 11.insert node before given element in LL
Node* inertbeforeEle(Node* head, int ele, int v) {
    if (head == NULL) return head;
    
    Node* temp = new Node(v);

    if (head -> data == ele) {
        temp -> next = head;
        return temp;
    }

    Node* dummy = head;

    while (dummy -> next) {
        
        if (dummy -> next -> data == ele) {
            temp -> next = dummy -> next;
            dummy -> next = temp;
            break;
        }

        dummy = dummy -> next ;
    }
    delete temp;
    return head;

}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}


int main(){

    vector<int> arr = {2,4,6,7,1,2,3,4,5};
    
    Node* head = convertVec(arr);
    cout << "1.Array to LL \n";
    printList(head);

    cout << "\n2.Length of LL is: " << lengthLL(head) << "\n";
    cout << "\n3.Element exist: " << exist(head, 2) << "\n";

    cout << "\n4.LL after deletion of head: \n";
    head = removehead(head);
    printList(head);

    cout <<"\n5.LL after deletion of Tail: \n";
    head = removetail(head);
    printList(head);

    cout << "\n6.LL after deletion of K th node: \n";
    head = delKth(head, 7);
    printList(head);

    cout << "\n7.after delete node of given element from LL: \n";
    head = delEle(head, 4);
    printList(head);

    cout << "\n8.after insert node to front of LL \n";
    head = insertFront(head, 9);
    printList(head);

    cout << "\n9.after insert node to rear of LL \n";
    head = insetRear(head, 10);
    printList(head);

    cout << "\n10.after insert node to k th position of LL \n";
    head = inertK(head, 2, 20);
    printList(head);

    cout << "\n11. after insert node to before given Element of LL \n";
    head = inertbeforeEle(head, 9, 30);
    printList(head);
    cout <<'\n';

}
  
```
### ouput
```
1.Array to LL 
2 -> 4 -> 6 -> 7 -> 1 -> 2 -> 3 -> 4 -> 5 -> nullptr

2.Length of LL is: 9

3.Element exist: 1

4.LL after deletion of head: 
4 -> 6 -> 7 -> 1 -> 2 -> 3 -> 4 -> 5 -> nullptr

5.LL after deletion of Tail:
4 -> 6 -> 7 -> 1 -> 2 -> 3 -> 4 -> nullptr

6.LL after deletion of K th node:
4 -> 6 -> 7 -> 1 -> 2 -> 3 -> 4 -> nullptr

7.after delete node of given element from LL:
6 -> 7 -> 1 -> 2 -> 3 -> 4 -> nullptr

8.after insert node to front of LL
9 -> 6 -> 7 -> 1 -> 2 -> 3 -> 4 -> nullptr

9.after insert node to rear of LL
9 -> 6 -> 7 -> 1 -> 2 -> 3 -> 4 -> 10 -> nullptr

10.after insert node to k th position of LL
9 -> 20 -> 6 -> 7 -> 1 -> 2 -> 3 -> 4 -> 10 -> nullptr

11. after insert node to before given Element of LL
30 -> 9 -> 20 -> 6 -> 7 -> 1 -> 2 -> 3 -> 4 -> 10 -> nullptr

```
