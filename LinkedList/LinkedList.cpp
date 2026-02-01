// All of the recursive implementations are slower and
// use much more memory (O(1) vs O(n)) but they are more intuitive and faster to
// code. Prefer iterative over recursive.

#include "LinkedList.h"
#include <iostream>

void TestLinkedList() {
  LinkedList<int> list;
  list.insert(1, 1);  // 1
  list.print();       // Output: 1
  list.insert(2, 2);  // 1, 2
  list.print();       // Output: 1, 2
  list.insert(3, 3);  // 1, 2, 3
  list.print();       // Output: 1, 2, 3
  list.insert(4, 4);  // 1, 2, 3, 4
  list.print();       // Output: 1, 2, 3, 4
  list.deleteNode(1); // 2, 3, 4
  list.print();       // Output: 2, 3, 4
  list.reverseList(); // 4, 3, 2
  std::cout << "Reversed list is: ";
  list.recursivePrint(list.head); // Output: 4, 3, 2
  std::cout << std::endl;
  std::cout << "Reversed reversed list is: ";
  list.recursiveReversePrint(list.head); // Output: 2, 3, 4
  std::cout << std::endl;
  list.recursiveReverseList(list.head); // 2, 3, 4
  std::cout << "List is ";
  list.recursivePrint(list.head); // Output: 2, 3, 4
  std::cout << std::endl;
}

int main() {
  TestLinkedList();

  return 0;
}
