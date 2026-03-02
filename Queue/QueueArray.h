#pragma once
#include <stdexcept>

// Type agnostic implementation
template <typename T> struct QueueArray {
  // For O(1) time we keep track of the first and last element's position
  // To maximize space utilization we will also use a circular array
  int rear{-1};
  int front{-1};
  int size;
  T *queue;
  QueueArray<T>(int initialSize) {
    size = initialSize;
    queue = new T[size]();
  }
  ~QueueArray() { delete[] queue; }
  void enqueue(T x) {
    // If array overflows, copy the contents into a new, 2x bigger array
    if ((rear + 1) % size == front) {
      const int oldSize{size};
      size *= 2;
      auto *newArray = new T[size]();
      // Iterate over every element and copy translating the circular array
      // position to the standard index
      for (int i = 0; i < oldSize; i++)
        newArray[i] = queue[(front + i) % oldSize];
      delete[] queue;
      queue = newArray;
      rear = oldSize;
      front = 0;
    } else if (isEmpty()) {
      rear = 0;
      front = 0;
    } else
      rear = (rear + 1) % size;
    // Add element to the end of the queue
    queue[rear] = x;
  }
  T dequeue() {
    if (isEmpty())
      throw std::runtime_error("Queue is empty");
    // If both front and rear match then only one element is in queue so we set
    // the queue as empty after dequeue
    else if (front == rear) {
      const T data = queue[front];
      front = -1;
      rear = -1;
      return data;
    } else {
      const T data = queue[front];
      // We increment the index by one but we wrap it around the array
      front = (front + 1) % size;
      return data;
    }
  }
  T peek() { return queue[front]; }
  bool isEmpty() { return rear == -1 && front == -1; }
};
