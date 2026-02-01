#pragma once
#include "../Stack/StackArray.h"
// For this algorithm we want to check if the parentheses
// follow a set of criteria listed here:
// - Every opening parenthesis needs to have a closing counterpart on its right
// - Every closing parenthesis needs to have an opening counterpart on its left
// - Parenthesis can only be closed once every other parenthesis opened after it
//   is closed beforehand
// - Last parenthesis unclosed will be the first closed
inline bool balancedParentheses(std::string str) {
  // Create a stack with an array of the size of the string
  // We choose the array implementation of the stack for this
  // algorithm because we know the max size, and using an array
  // saves on memory allocation cost (once vs every element added/removed)
  StackArray<char> stack(int(str.length()));
  for (char c : str) {
    // For this implementation we store the opposite symbol in the stack
    // than the one we matched, this allows for a single comparison when
    // checking if the parentheses were closed
    if (c == '(') {
      stack.push(')');
    } else if (c == '[') {
      stack.push(']');
    } else if (c == '{') {
      stack.push('}');
    }
    // We ignore chars that aren't parentheses
    else if (c == ')' || c == ']' || c == '}') {
      if (stack.isEmpty() || stack.top() != c)
        return false; // Edge case: closing parenthesis without opening one first OR
                  // closing parentheses in incorrect order
      stack.pop(); // Remove the closed parenthesis from the stack
    }
  }
  return stack.isEmpty();
}
