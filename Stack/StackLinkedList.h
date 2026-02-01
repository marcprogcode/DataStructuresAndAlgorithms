#pragma once

#include <iostream>
// Singly Linked List is more appropriate than a Doubly for a Stack
template <typename T> // Type-agnostic implementation.
struct Node {
	T data;
	Node<T>* next;
};

template <typename T> // Type-agnostic implementation.
struct StackLinkedList {
	Node<T>* head = nullptr;
	~StackLinkedList() {
		while (head) {
			pop(); // Iteratively pop all elements to free memory
		}
	}
	void push(T x) {
		Node<T>* newNode = new Node<T>();
		newNode->data = x;
		newNode->next = head; // Point new node to old head
		head = newNode;
	}
	void pop() {
		if (!head) return;
		Node<T>* toDelete = head;
		head = head->next; // Move head to next node
		delete toDelete;
	}
	T top() {
		return head->data;
	}
	bool isEmpty() {
		return head == nullptr;
	}
};