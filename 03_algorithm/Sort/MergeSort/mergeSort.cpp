/*
MergeSort(headRef)
1) If the head is NULL or there is only one element in the Linked List 
    then return.
2) Else divide the linked list into two halves.  
      FrontBackSplit(head, &a, &b);  //a and b are two halves 
3) Sort the two halves a and b.
      MergeSort(a);
      MergeSort(b);
4) Merge the sorted a and b (using SortedMerge() discussed here) 
   and update the head pointer using headRef.
     *headRef = SortedMerge(a, b);

From : https://www.geeksforgeeks.org/merge-sort-for-linked-list/
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Node {
  public:
    int data;
    Node* next;
};

/* Split the given list source into front and back halves,
   and return the two lists using the reference parameters.
   If the length is odd, the extra node should go in the front list.
   Use the fast/slow pointer strategy. */
void FrontBackSplit(Node* source, Node** frontRef, Node** backRef){
  Node* fast;
  Node* slow;
  slow = source;
  fast = source->next;

  //Advance 'fast' two nodes, and advance 'slow' one node.
  while(fast != NULL){
    fast = fast->next;
    if(fast != NULL){
      slow = slow->next;
      fast = fast->next;
    }
  }

  //'slow' is before the midpoint in the list, so split it in at that point.
  *frontRef = source;
  *backRef = slow->next;
  slow->next = NULL;
}

Node* SortedMerge(Node* a, Node* b){
  Node* result = NULL;

  //Base case.
  if(a == NULL)
    return b;
  else if(b == NULL)
    return a;

  //Pick either a or b, and recur.
  if(a->data <= b->data){
    result = a;
    result->next = SortedMerge(a->next, b);
  }
  else{
    result = b;
    result->next = SortedMerge(a, b->next);
  }
  return result;
}

//Sort the linked list by changing next pointers (not data)
void MergeSort(Node ** headRef){
  Node* head = *headRef;
  Node* a;
  Node* b;

  //Base case -- length 0 or 1.
  if((head == NULL) || (head->next == NULL)){
    return;
  }

  //Split head into 'a' and 'b' sublists.
  FrontBackSplit(head, &a, &b);

  //Recursively sort the sublists.
  MergeSort(&a);
  MergeSort(&b);

  //Merge the two sorted lists together.
  *headRef = SortedMerge(a, b);
}





//Print the given linked list.
void printList(Node* node){
  while(node != NULL){
    cout << node->data << " ";
    node = node->next;
  }
  cout << endl;
}

//Insert a node for initialization.
void nodePush(Node ** headRef, int newData){
  //Allocate a new node and assign the data.
  Node* newNode = new Node();
  newNode->data = newData;

  //Link the old list of the new node.
  newNode->next = *headRef;

  //Move the head to point to the new node.
  *headRef = newNode;
}

int main(void) {
    Node* a = NULL;

    //Create a list : 2->3->20->5->10->15.
    nodePush(&a, 15);
    nodePush(&a, 10);
    nodePush(&a, 5);
    nodePush(&a, 20);
    nodePush(&a, 3);
    nodePush(&a, 2);

    MergeSort(&a);

    cout << "Sorted Linked List: " << endl;
    printList(a);
    
    return 0;
}