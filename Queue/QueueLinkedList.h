#pragma once
#include <stdexcept>

// Type agnostic implementation
template <typename T> struct Node {
  T data;
  Node *next;
};

template <typename T> struct QueueLinkedList {
  // For O(1) time we keep track of the first and last element's position
  Node<T> *head = nullptr;
  Node<T> *tail = nullptr;

  // Iteratively free memory
  ~QueueLinkedList() {
    while (head)
      dequeue();
  }
  // Add node at the end of the list
  void enqueue(T x) {
    auto *newNode = new Node<T>();
    newNode->data = x;
    newNode->next = nullptr;
    if (!head) {
      head = newNode;
      tail = newNode;
      return;
    }
    tail->next = newNode;
    tail = newNode;
  }
  // Delete and return first node
  T dequeue() {
    if (isEmpty())
      throw std::runtime_error("Queue is empty");
    auto data = head->data;
    auto *deleteNode = head;
    head = head->next;
    if (!head)
      tail = nullptr;
    delete deleteNode;
    return data;
  }
  T peek() { return head->data; }
  bool isEmpty() { return head == nullptr; }
};
