#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int partitionArray(std::vector<int> &v, int start, int end) {
    int pivot = start;
    int l = start + 1, r = end;

    while(l <= r) {
        if(v[l] < v[pivot])
            l++;
        else if(v[r] >= v[pivot])
            r--;
        else
            swap(v[l], v[r]);
    }
    swap(v[pivot], v[r]);
    return r; 
}

void quickSort(std::vector<int> &v, int start, int end) {
    if (start >= end) return;

    int pivot = partitionArray(v, start, end);
    quickSort(v, start, pivot);
    quickSort(v, pivot + 1, end);
}

int main(void) {
    //vector<int> v{5, 4, 3, 2, 1};
    vector<int> v{ 5, 5 };
    
    quickSort(v, 0, v.size() - 1);
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}