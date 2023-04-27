#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void chooseMinimum(std::vector<int> &v, int miniInd, int chkInd, int end) {
  if(chkInd > end)
    return;

  chooseMinimum(v, miniInd, chkInd + 1, end);
  if(v[chkInd] < v[miniInd])
    swap(v[miniInd], v[chkInd]);
}

void selectMinimum(std::vector<int> &v, int miniInd, int end) {
  //start from miniInd==0.
  if(miniInd < 0)
    return;

  //Recursively call until miniInd<0.
  selectMinimum(v, miniInd - 1, end);
  //Choose minimum from v[miniInd+1] to v[end]
  chooseMinimum(v, miniInd, miniInd + 1, end);
}

void selectionSort(std::vector<int> &v, int start, int end) {
  selectMinimum(v, end - 1, end);

}

int main(void) {
    //vector<int> v{5, 4, 3, 2, 1, 0};
    //vector<int> v{ 5, 5 };
    vector<int> v{50, 2, 3, 2, 1, 0};
    
    selectionSort(v, 0, v.size() - 1);
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}