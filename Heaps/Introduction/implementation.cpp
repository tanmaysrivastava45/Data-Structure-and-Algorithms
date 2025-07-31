// #include<bits/stdc++.h>
// using namespace std;

// class heap{
//    public:
//     int arr[100];
//     int size;
//     heap(){
//     arr[0]=-1;
//     size = 0;
//     }
//     void insert(int val){
//         size = size + 1;
//         int idx = size;
//         arr[idx]= val ;
//         while(idx>1){
//             int parent = idx/2;
//             if(arr[parent]<arr[idx]){
//                 swap(arr[parent], arr[idx]);
//                 idx = parent;
//             }else return;
//         }
//     }
//     void print(){
//         for(int i=0;i<=size;i++){
//             cout<<arr[i]<<" ";
//         }
//         cout<<endl;
//     }
//     void deleteit(){
//         if(size==0){
//             cout<<"alreaady empty";
//             return;
//         }else{

//         }
//     }

// };

// int main(){
//     heap h;
//     h.insert(32);
//     h.insert(45);
//     h.insert(56);
//     h.insert(98);
//     h.insert(18);
//     h.print();
// }


#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 1 && heap[i] > heap[i / 2]) {
            swap(heap[i], heap[i / 2]);
            i /= 2;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size() - 1;
        while (2 * i <= n) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left <= n && heap[left] > heap[largest]) largest = left;
            if (right <= n && heap[right] > heap[largest]) largest = right;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

public:
    MaxHeap() {
        heap.push_back(-1); // dummy element at index 0 for 1-based indexing    
    }

    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void deleteMax() {
        if (heap.size() <= 1) {
            cout << "Heap is empty.\n";
            return;
        }

        heap[1] = heap.back();
        heap.pop_back();
        heapifyDown(1);
    }

    void print() {
        for (int i = 1; i < heap.size(); ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    int getMax() {
        if (heap.size() <= 1) return -1;
        return heap[1];
    }

    int size() {
        return heap.size() - 1;
    }
};
int main() {
    MaxHeap h;
    h.insert(50);
    h.insert(30);
    h.insert(20);
    h.insert(40);
    h.insert(60);

    h.print();        // Output: 60 50 20 30 40
    cout << h.getMax() << endl;  // Output: 60

    h.deleteMax();
    h.print();        // Output: 50 40 20 30
}
