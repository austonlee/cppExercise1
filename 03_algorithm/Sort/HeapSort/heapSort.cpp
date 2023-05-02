#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void MaxHeapify(std::vector<int> &v, int root, int end) {
  int largest = -1;
  while(largest != root) {
    int left = 2 * root;//Left child index.
    int right = 2 * root + 1;//Right child index

    if(left <= end && v[left] > v[root])
      largest = left;
    else
      largest = root;//root is bigger or no child.

    if(right <= end && v[right] > v[largest])
      largest = right;
    
    if(largest != root) {
      swap(v[largest], v[root]);
      root = largest;
      largest = -1;
    }
    else//largest == root, break.
      break;
  }

}

void buildMaxHeap(std::vector<int> &v) {
  //Do MaxHeapify on root and subroot.
  int tempRootIdx = v.size()/ 2; //Index for last subroot.

  for(int i = tempRootIdx; i >= 1; i--) {
    MaxHeapify(v, i, v.size() - 1);//-1 is for array index starting from 0.
  }
}

void heapSort(std::vector<int> &v) {
  //1. Insert '0' to v[0]. Heap binary tree start from index 1.
  v.insert(v.begin(), 0);

  //2. Build max heap from v[].
  buildMaxHeap(v);

  //3. Sort from heap.
  int tempEndIdx = v.size() - 1;
  for(int i = v.size() - 1; i >= 2; i--) {
    swap(v[1], v[i]);
    tempEndIdx--;
    MaxHeapify(v, 1, tempEndIdx);
  }
  
  //4. Remove v[0].
  v.erase(v.begin());
}

int main(void) {
    //int arr[] = {5, 4, 3, 2, 1, 0};
    //int arr[] = { 5, 5 };
    int arr[] = {60, 50, 2, 3, 2, 1, 0};
    std::vector<int> v(arr, arr+sizeof(arr)/sizeof(int));

    heapSort(v);
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}