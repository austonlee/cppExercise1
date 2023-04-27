#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void recInsert(vector<int> &v, int value){
  //Correct position found.Insert the 'last' value from recInsertSort().
  if(v.size() == 0 || v.back() < value)
    return v.push_back(value);
  
  //Keep the last element in 'last'.
  int last = v.back();
  v.pop_back();
  //Recursively find the correct position and insert the 'last' from recInsertSort().
  recInsert(v, value);
  //Insert the temporarily kept 'last'.
  v.push_back(last);
}

void recInsertionSort(std::vector<int> &v) {
  //Until 1 element in vector. Start to insert kept last element.
  if(v.size() <= 1)
    return;

  //Keep last element in last temporarily.
  int last = v.back();
  v.pop_back();

  //Recursively remove last element and keep in 'last'.
  recInsertionSort(v);
  //Insert 'last' in order.
  recInsert(v, last);
}

int main(void) {
    //vector<int> v{5, 4, 3, 2, 1, 0};
    //vector<int> v{ 5, 5 };
    vector<int> v{50, 2, 3, 2, 1, 0};
    
    recInsertionSort(v);
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}