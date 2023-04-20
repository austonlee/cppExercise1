#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int merge(std::vector<int> &v, int start, int middle, int end) {
    int leftIdx = start;
    int rightIdx = middle + 1;
    int vLen = v.size();
    vector<int> sortedV;

    for (int i = start; i <= end; i++) {
        if(leftIdx > middle)
          sortedV.push_back(v[rightIdx++]);
        else if(rightIdx > end)
          sortedV.push_back(v[leftIdx++]);
        else if(v[leftIdx] <= v[rightIdx])
          sortedV.push_back(v[leftIdx++]);
        else
          sortedV.push_back(v[rightIdx++]);
    }
    for (int i = start; i <= end; i++)
    {
        v.at(i) = sortedV.at(i - start);
    }
}

void mergeSort(std::vector<int> &v, int start, int end) {
    if (start < end){
      int middle = (start + end)/2;
      mergeSort(v, start, middle);
      mergeSort(v, middle+1, end);
      merge(v, start, middle, end);
    }
}

int main(void) {
    //vector<int> v{5, 4, 3, 2, 1, 0};
    //vector<int> v{ 5, 5, 3, 3};
    vector<int> v{0, 1, 2, 3, 3, 5, 2};
    
    mergeSort(v, 0, v.size() - 1);
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}