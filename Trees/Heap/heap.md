## HEAP :
- A Heap is a special type of binary tree that satisfies specific ordering rules. It is mainly used to efficiently get the maximum or minimum element.
### 🔹 Types of Heap
1. 1️⃣ Max Heap
- The parent node is always greater than or equal to its children.
- The largest element is always at the root.

2. 2️⃣ Min Heap
- The parent node is always smaller than or equal to its children.
- The smallest element is always at the root.

### 🔹 Important Properties of Heap
- ✔ It is a Complete Binary Tree
- All levels are completely filled except possibly the last level.
- Nodes are filled from left to right.
- ✔ Usually stored in arrays instead of pointers.

### 🔹 Array Representation
- If index = i
    - Left child → 2*i + 1
    - Right child → 2*i + 2
    - Parent → (i-1)/2

### 🔹 Time Complexity
| Operation   | Complexity |
| ----------- | ---------- |
| Insert      | O(log n)   |
| Delete root | O(log n)   |
| Access root | O(1)       |

### 🔹 Where Heap is Used
- ✅ Priority Queue
- ✅ Heap Sort
- ✅ Graph Algorithms (Dijkstra, Prim)
- ✅ Scheduling problems
```c
  void heapifyUp(int i){
      while(i>0){
          int parent = (i-1)/2;
          if(v[parent]>v[i]){
              swap(v[parent],v[i]);
          }else return;
          i=parent;
      }
  }
  void heapifyDown(){
      int i=0 , size = v.size();
      while(1){
          int l = 2*i+1 , r = 2*i+2;
          int s = i;
          if(l<size && v[l]<v[s])  s = l;
          if(r<size && v[r]<v[s]) s = r;
          if(s==i) return;
          swap(v[s],v[i]);
          i=s;
      }
  }
```

## Build Heap :
- Why Build Heap is O(n) not O(n log n)
    - Because most heapify operations occur near leaf nodes which require very small work.
```c
void heapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest])
        smallest = left;

    if(right < n && arr[right] < arr[smallest])
        smallest = right;

    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}
void buildHeap(vector<int>& arr) {
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
    }
}
```

## Heap sort :
```c
class Solution {
  public:
    void heapify(vector<int>& arr , int i , int n){
        int l = 2*i+1  , r = 2*i+2;
        int high = i;
        // Given an array arr[]. The task is to sort the array elements by Heap Sort.
        if(l<n && arr[l]>arr[high]) high=l;
        if(r<n && arr[r]>arr[high]) high=r;
        
        if(high==i) return;
        swap(arr[high],arr[i]); i=high;
        heapify(arr , high , n);
    }
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        int n = arr.size();
        
        for(int i=(n/2)-1;i>=0;i--) heapify(arr,i,n);
        
        for(int i=n-1;i>0;i--){
            swap(arr[0],arr[i]);
            heapify(arr,0,i);
        }
    }
};
```



