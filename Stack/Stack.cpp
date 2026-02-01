#include "../Algorithms/balancedParentheses.h"
#include "../Algorithms/reverseString.h"
#include "StackArray.h"
#include "StackLinkedList.h"
#include <iostream>

int main() {
  StackArray<int> StackArr(10);
  int testSize = 11;
  for (int i = 0; i < testSize; i++)
    StackArr.push(i);
  std::cout << StackArr.top() << StackArr.isEmpty();
  for (int i = 0; i < testSize; i++)
    StackArr.pop();
  std::cout << StackArr.isEmpty() << std::endl;

  StackLinkedList<int> StackList;
  for (int i = 0; i < testSize; i++)
    StackList.push(i);
  std::cout << StackList.top() << StackList.isEmpty();
  for (int i = 0; i < testSize; i++)
    StackList.pop();
  std::cout << StackList.isEmpty() << std::endl;

  std::cout << balancedParentheses("((([text]{})))") << std::endl;
  std::cout << reverseString("Hello!!!");
}
