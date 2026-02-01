// All of the recursive implementations are slower and use much more memory
// (O(1) vs O(n)) but they are more intuitive and faster to code. Prefer
// iterative over recursive. The insert at n position and delete node has split
// traversal optimization using head/tail access based on the size of the list.

#include "DoublyLinkedList.h"
#include <iostream>

void TestDoublyLinkedList() {
  DoublyLinkedList<int> list;
  list.insertAtHead(4);
  list.print(); // List is: 4
  list.insertAtHead(3);
  list.print(); // List is: 3 4
  list.insertAtHead(2);
  list.print(); // List is: 2 3 4
  list.insertAtHead(1);
  list.print(); // List is: 1 2 3 4
  list.insertAtTail(5);
  list.print(); // List is: 1 2 3 4 5
  list.insertAtTail(6);
  list.insert(7, 7);
  list.insert(0, 1);
  list.reversePrint(); // Reverse list is: 7 6 5 4 3 2 1 0
  std::cout << "List size: " << list.size << std::endl; // List size : 8
  list.recursivePrint(list.head);
  std::cout << std::endl;
  list.recursiveReversePrint(list.tail);
  std::cout << std::endl;
  list.reverseList();
  list.print();        // List is : 7 6 5 4 3 2 1 0
  list.reversePrint(); // Reverse list is: 0 1 2 3 4 5 6 7
  list.deleteNode(1);
  list.print(); // List is: 6 5 4 3 2 1 0
  list.deleteNode(3);
  list.print(); // List is: 6 5 3 2 1 0
  list.deleteNode(5);
  list.print(); // List is: 6 5 3 2 0
}

int main() {
  TestDoublyLinkedList();
  return 0;
}
