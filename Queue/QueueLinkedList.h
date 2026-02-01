#pragma once

// Type agnostic implementation
template <typename T> struct Node {
  T data;
  Node *next;
};

template <typename T> struct QueueLinkedList {
  Node<T> *head = nullptr;

  // Iteratively free memory
  ~QueueLinkedList() {
    while (head) {
      dequeue();
    }
  }
  // Add node at the end of the list
  void enqueue(T x) {
    Node<T> *newNode = new Node<T>();
    newNode->data = x;
    newNode->next = nullptr;

    if (!head) {
      head = newNode;
      return;
    }
    Node<T> *lastNode = head;
    while (lastNode->next) {
      lastNode = lastNode->next;
    }
    lastNode->next = newNode;
  }
  // Delete first node
  void dequeue() {
    if (!head)
      return;
    Node<T> *deleteNode = head;
    head = head->next;
    delete deleteNode;
  }

  // Get first node
  T peek() { return head->data; }
  bool isEmpty() { return head == nullptr; }
};
