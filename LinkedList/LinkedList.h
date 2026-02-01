#pragma once

#include <iostream>

template <typename T> // Type-agnostic implementation.
struct Node {
  T data;
  Node<T> *next;
};

template <typename T> // List and node shall share type
struct LinkedList {
  // Destructor de-allocates memory from the heap after deletion of the list
  ~LinkedList() {
    Node<T> *current;
    current = head;
    // Traverse through the list
    while (current != nullptr) {
      Node<T> *temp1;
      temp1 = current;         // Saves the location of the current node
      current = current->next; // Traverses to the next node
      delete temp1;            // Free the memory of this iteration's node
    }
  }
  void insert(T x, int n) {
    Node<T> *newNode = new Node<T>(); // Allocates space for new node

    newNode->data = x;
    newNode->next = nullptr;

    // If added to the front, point node to head then head to new node
    if (n == 1) {
      newNode->next = head;
      head = newNode;
      return;
    }
    // Traverse to the node before the position, point it to the new node, then
    // point new node to node previously in the position
    Node<T> *oldNode = head;
    for (int i = 1; i < n - 1; i++) {
      oldNode = oldNode->next;
    }
    newNode->next =
        oldNode->next; // Set the next node pointer to match the old node at n
    oldNode->next =
        newNode; // Set the old next node pointer to match the new node
  }
  void deleteNode(int n) {
    // If deleting the first node, point head to next, then de-allocate memory
    // for deleted node
    if (n == 1) {
      Node<T> *toDelete = head;
      head = head->next;
      delete toDelete;
      return;
    }
    Node<T> *prevToDelete = head;
    // Traverse to the node before the position, point it to the next node after
    // deleted, then de-allocate memory for deleted node
    for (int i = 1; i < n - 1; i++) {
      prevToDelete = prevToDelete->next;
    }
    Node<T> *toDelete = prevToDelete->next;
    prevToDelete->next = toDelete->next;
    delete toDelete;
  }
  void reverseList() {
    Node<T> *current, *prev, *next;
    current = head;
    prev = nullptr;
    // Traverse the list while switching next node for prev node
    while (current != nullptr) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    // Finally, set head to the new first node
    head = prev;
  }
  void recursiveReverseList(Node<T> *p) {
    if (p == nullptr)
      return;
    if (p->next == nullptr) {
      head = p;
      return;
    }
    recursiveReverseList(p->next);
    // After recursive call, travelling backwards
    p->next->next =
        p; // Set the next pointer of the next node to point towards the current
           // node, so instead of pointing forward it points backwards
    p->next = nullptr; // Set the next pointer of this node to point towards
                       // null (assuming it's last, but it will get overwritten
                       // if there are any more backwards steps)
  }
  void recursiveReversePrint(Node<T> *p) {
    if (p == nullptr)
      return;
    recursiveReversePrint(p->next);
    std::cout << p->data << " "; // After recursive call, travelling backwards
  }
  void recursivePrint(Node<T> *p) {
    if (p == nullptr)
      return;
    std::cout << p->data << " "; // Before recursive call, travelling forwards
    recursivePrint(p->next);
  }
  void print() {
    Node<T> *traverser = head;
    std::cout << "List is: ";
    // Traverse the list printing the data on each node
    while (traverser != nullptr) {
      std::cout << traverser->data << " ";
      traverser = traverser->next;
    }
    std::cout << std::endl;
  }
  Node<T> *head = nullptr;
};
