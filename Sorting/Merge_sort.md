### cpp
```cpp

void merge(vector<int>& vec, int low, int mid, int high) {
    vector<int> temp;

    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high){
        if(vec[left] <= vec[right]) {
            temp.push_back(vec[left++]);
        } 
        else{
            temp.push_back(vec[right++]);
        }
    }

    while (left <= mid) {
        temp.push_back(vec[left++]);
    }

    while (right <= high) {
        temp.push_back(vec[right++]);
    }

    for (int i = low; i <= high; i++) {
        vec[i] = temp[i - low];
    }

}

void mergesort(vector<int>& vec, int low, int high){
    if (low >= high) return;

    int mid = low + (high - low)/ 2;
    mergesort(vec, low, mid);
    mergesort(vec, mid + 1, high);
    merge(vec, low, mid, high);
    
}

int main(){
    vector <int> arr = {3,2,1,3,7,5,4};

    mergesort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << "\t";
    }

    return 0;

}
```
### Output
```
1  2  3  3  4  5  7
```
