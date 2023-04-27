#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void insertionSort(std::vector<int> &v) {
  int unsortedIdx, sortedIdx, key;
  int size = v.size();

  for(unsortedIdx = 1; unsortedIdx < size; unsortedIdx++){
    key = v[unsortedIdx];
    sortedIdx = unsortedIdx - 1;
    while(sortedIdx >= 0 && key < v[sortedIdx]){
      v[sortedIdx + 1] = v[sortedIdx];
      sortedIdx = sortedIdx - 1;
    }
    v[sortedIdx + 1] = key;
  }
}

int main(void) {
    //vector<int> v{5, 4, 3, 2, 1, 0};
    //vector<int> v{ 5, 5 };
    vector<int> v{5, 2, 3, 2, 1, 0};
    
    insertionSort(v);
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}