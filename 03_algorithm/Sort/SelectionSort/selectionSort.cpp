#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void selectionSort(std::vector<int> &v) {
  int size = v.size();
  //Select minimun value for v[miniInd] (v[0] ~ v[n-2]).
  for(int miniInd = 0; miniInd < size -1; miniInd++) {
    //Select minimun value from v[miniInd+1] ~ v[n-1].
    for(int currentChkInd= miniInd + 1; currentChkInd < size; currentChkInd++) {
      if(v[currentChkInd] < v[miniInd]) {
        swap(v[miniInd], v[currentChkInd]);
      }
    }
  }

}

int main(void) {
    //vector<int> v{5, 4, 3, 2, 1, 0};
    //vector<int> v{ 5, 5 };
    vector<int> v{50, 2, 3, 2, 1, 0};
    
    selectionSort(v);
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}