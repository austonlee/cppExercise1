#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int partitionArray(std::vector<int> &v, int start, int end) {
       if (start >= end) return -1;
      int pivot = end, i = start, j = start;
      //Swap v[j] and v[i] if v[j] < v[Pivot]. Pivot is the most right element.
      //j goes through v[]. v[start ~ i-1] < v[Pivot]. Return i which is new pivot.
      while(j < end){
        if(v[j] < v[pivot]){
          swap(v[i], v[j]);
          i++;
        }
        j++;
      }
      swap(v[pivot], v[i]);
      return i;
}

void quickSort(std::vector<int> &v, int start, int end) {
    if (start >= end) return;

    int pivot = partitionArray(v, start, end);
    //Divide v and exclude the pivot which is in the correct position.
    quickSort(v, start, pivot - 1);
    quickSort(v, pivot + 1, end);
}

int main(void) {
    vector<int> v{5, 4, 3, 2, 1, 0};
    //vector<int> v{ 5, 5 };
    
    quickSort(v, 0, v.size() - 1);
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}