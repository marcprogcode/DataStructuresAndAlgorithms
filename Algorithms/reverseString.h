#pragma once
#include "../Stack/StackArray.h"
// Naturally pushing then retrieving the values will reverse the list
inline std::string reverseString(std::string str) {
  // We choose an array based stack as we know its max size
  // and we can save on memory allocation time (once vs every char)
  StackArray<char> stack(int(str.length()));
  for (char c : str) {
    stack.push(c);
  }
  for (int i = 0; i < str.length(); i++) {
    str[i] = stack.top();
    stack.pop();
  }
  return str;
}
