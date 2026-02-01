#pragma once
#include <iostream>

template <typename T> // Type-agnostic implementation.
struct StackArray {
  T *stack = nullptr;
  int topStack = -1;
  int stackSize = -1;
  StackArray(int n) {
    stackSize = n;
    stack = new T[stackSize]();
  }
  ~StackArray() { delete[] stack; }
  void push(T x) {
    topStack++;
    // If an overflow occurs we double the size of the array and copy over the
    // elements
    if (topStack >= stackSize) {
      stackSize *= 2;
      T *newStack = new T[stackSize]();
      for (int i = 0; i < stackSize / 2; i++)
        newStack[i] = stack[i];
      delete[] stack; // Free old memory
      stack = newStack;
    }
    stack[topStack] = x;
  }
  void pop() {
    if (topStack == -1)
      return; // Return if stack is already empty
    topStack--;
  }
  T top() { return stack[topStack]; }
  bool isEmpty() { return topStack == -1; }
};
