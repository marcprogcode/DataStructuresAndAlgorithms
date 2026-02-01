#pragma once

// Type agnostic implementation
template <typename T> struct QueueArray {
  int lastElement = -1;
  int size = -1;
  T *queue;
  QueueArray<T>(int initialSize) {
    size = initialSize;
    queue = new T[size]();
  }
  ~QueueArray() { delete[] queue; }
  void enqueue(T x) {
    lastElement++;
    // If array overflows, copy the contents into a new, 2x bigger array
    if (lastElement >= size) {
      size *= 2;
      T *newArray = new T[size]();
      for (int i = 0; i < size / 2; i++) {
        newArray[i] = queue[i];
      }
      delete[] queue;
      queue = newArray;
    }
    // Add element to the end of the queue
    queue[lastElement] = x;
  }
  void dequeue() {
    if (lastElement <= -1)
      return;
    // Shift over the entire array by one
    for (int i = 1; i <= lastElement; i++) {
      queue[i - 1] = queue[i];
    }
    lastElement--;
  }
  T peek() { return queue[0]; }
  bool isEmpty() { return lastElement == -1; }
};
