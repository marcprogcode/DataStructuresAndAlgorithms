#pragma once

#include <iostream>
// Singly Linked List is more appropiate than a Doubly for a Stack
template <typename T> // Type-agnostic implementation.
struct Node {
	T data;
	Node<T>* next;
};

template <typename T> // Type-agnostic implementation.
struct StackLinkedList {
	Node<T>* head = nullptr;
	void push(T x) {
		Node<T>* newNode = new Node<T>();
		newNode->data = x;
		newNode->next = head; // Point new node to old head
		head = newNode;
	}
	void pop() {
		if (!head) return;
		Node<T>* toDelete = head;
		head = head->next;
		delete toDelete;
	}
	int top() {
		return head->data;
	}
	bool isEmpty() {
		return head ? false : true;
	}
};