#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void bubbleSort(std::vector<int> &v) {
  int size = v.size();
  //Swap the biggest element to i in each loop.
  for(int i = size - 1; i > 0; i--) {
    //Swap the bigger element to behind.
    for(int j = 0; j < i; j++) {
      if(v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
      }
    }
  }

}

int main(void) {
    //vector<int> v{5, 4, 3, 2, 1, 0};
    //vector<int> v{ 5, 5 };
    vector<int> v{50, 2, 3, 2, 1, 0};

    bubbleSort(v);
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}