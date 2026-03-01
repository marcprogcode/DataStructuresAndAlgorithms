#pragma once
#include "../Stack/StackArray.h"
#include "../Stack/StackLinkedList.h"
#include <iostream>
#include <string>

constexpr char mult = '*';
constexpr char dvd = '/';
constexpr char add = '+';
constexpr char sub = '-';
inline int isNum(char c) {
  // The key to this function is the ASCII standard
  // as numbers are defined in a consecutive sequence
  // of ints, therefore we can set upper and lower bounds
  // to know if it's a number, and then calculate its
  // distance to 0 to know what the number is
  if (c >= '0' && c <= '9') {
    return c - '0';
  } else
    return -1;
}
inline float evalPostfixExpression(std::string str) {
  StackLinkedList<float> expression;
  float num = 0;
  int digit;
  for (char c : str) {
    digit = isNum(c);
    if (digit != -1) {
      if (num != 0) {
        // To allow for > 9 numbers, we shift by 1 decimal
        // the previous number then add the digit we just read
        num *= 10;
      }
      num += digit;
    } else if (c == ' ') {
      // If we've just read a number and we see a space the number is finished
      // so we add it to the expression stack
      if (num != 0) {
        expression.push(num);
        num = 0;
      }
    } else {
      // If we see an operator, we grab and remove the first 2 numbers in the
      // expression then perform the operation on them and push the result.
      // (inverse order because of the properties of the stack)
      float y = expression.pop();
      float x = expression.pop();
      if (c == mult) {
        expression.push(x * y);
      } else if (c == dvd) {
        expression.push(x / y);
      } else if (c == add) {
        expression.push(x + y);
      } else if (c == sub) {
        expression.push(x - y);
      }
    }
  }
  // After completing the loop we'll find the result on the top of the stack
  return expression.top();
}

inline float evalPrefixExpression(std::string str) {
  StackLinkedList<float> expression;
  float num{0};
  int multiplier{0};
  int digit;
  bool isParsing;
  // Iterate the string backwards
  // For C++11 std::views::reverse is not available (C++20)
  for (auto it = str.rbegin(); it != str.rend(); ++it) {
    char c = *it;
    digit = isNum(c);
    if (digit != -1) {
      // Shift the digit by the multiplier
      num += digit * (float)pow(10, multiplier);
      multiplier++;
      isParsing = true;
    } else if (c == ' ') {
      // If we've just read a number and we see a space the number is finished
      // so we add it to the expression stack
      if (isParsing) {
        expression.push(num);
        num = 0;
        multiplier = 0;
        isParsing = false;
      }
    } else {
      // If we see an operator, we grab and remove the first 2 numbers in the
      // expression then perform the operation on them and push the result.
      // (inverse order because of the properties of the stack)
      float x = expression.pop();
      float y = expression.pop();
      if (c == mult) {
        expression.push(x * y);
      } else if (c == dvd) {
        expression.push(x / y);
      } else if (c == add) {
        expression.push(x + y);
      } else if (c == sub) {
        expression.push(x - y);
      }
    }
  }
  // After completing the loop we'll find the result on the top of the stack
  return expression.top();
}

// Helper function to check the order of operations
inline bool isHigherPriority(char c1, char c2) {
  int v1, v2;
  if (c1 == mult || c1 == dvd) {
    v1 = 2;
  }
  if (c1 == add || c1 == sub) {
    v1 = 1;
  }
  if (c2 == mult || c2 == dvd) {
    v2 = 2;
  }
  if (c2 == add || c2 == sub) {
    v2 = 1;
  }
  return v1 >= v2;
}

inline std::string infixToPostfix(std::string str) {
  std::string result;
  // We set up a stack where we add the operators
  StackLinkedList<char> stack;
  bool parsingNum = false;

  for (char c : str) {
    if (isNum(c) != -1) {
      // If we're starting a new number add a space separator first
      if (!parsingNum) {
        if (!result.empty())
          result += ' ';
        parsingNum = true;
      }
      result += c;
    } else if (c == ' ') {
      // Spaces in the input just end the current number
      parsingNum = false;
    } else {
      // Operator ends any current number
      parsingNum = false;
      // Pop higher-or-equal priority operators from the stack
      while (!stack.isEmpty() && isHigherPriority(stack.top(), c)) {
        if (!result.empty())
          result += ' ';
        result += stack.pop();
      }
      stack.push(c);
    }
  }
  // Pop remaining operators
  while (!stack.isEmpty()) {
    if (!result.empty())
      result += ' ';
    result += stack.pop();
  }
  return result;
}
