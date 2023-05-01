#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void bubbleUp(std::vector<int> &v, int bubbleUpEnd) {
  //Recursive bubbleUp() from 0 to bubbleUpEnd.
  if(bubbleUpEnd < 0)
    return;
  bubbleUp(v, bubbleUpEnd - 1);
  //Swap if current element > next element.
  if(v[bubbleUpEnd] > v[bubbleUpEnd + 1])
    swap(v[bubbleUpEnd], v[bubbleUpEnd + 1]);
}

void bubbleSort(std::vector<int> &v, int start, int end) {
  //Recursive bubbleSort() from (end-1) to start.
  if(start == end)
    return;

  //From (end-1) to start, do recurrsive bubleUp to get its biggest element. 
  bubbleSort(v, start + 1, end);
  bubbleUp(v, start);
}

int main(void) {
    //vector<int> v{5, 4, 3, 2, 1, 0};
    //vector<int> v{ 5, 5 };
    vector<int> v{60, 50, 2, 3, 2, 1, 0};

    bubbleSort(v, 0, v.size() - 1);
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}