#pragma once

#include <iostream>

template <typename T> // Type-agnostic implementation.
struct Node {
	T data;
	Node<T>* next;
	Node<T>* prev;
};
template <typename T> // Type-agnostic implementation.
struct DoublyLinkedList {
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	int size = 0;
	// Deconstructor de-allocates memory from the heap after deletion of the list
	~DoublyLinkedList() {
		Node<T>* current = head;
		// Traverse through the list
		while (current != nullptr) {
			Node<T>* temp1;
			temp1 = current; // Saves the location of the current node
			current = current->next; // Traverses to the next node
			delete temp1; // Free the memory of this iteration's node
		}
	}

	void insert(T x, int n) {
		Node<T>* newNode = new Node<T>(); // Allocates space for new node

		newNode->data = x;

		// If added to the front, point next to (old)head then head to new node, then prev to null as it is first element
		if (n == 1) {
			newNode->next = head;
			newNode->prev = nullptr;
			if (head) head->prev = newNode; // If a previous head node existed, then point its prev towards new node
			else tail = newNode; // Else, this node is the first node so it will be both head and tail
			head = newNode;
			size++;
			return;
		}
		// If added to the back, point prev to (old)tail then tail to new node, then next to null as it is last element
		else if (n == size + 1) { // Size +1 as the new length of the list is not accounted for yet
			newNode->prev = tail;
			newNode->next = nullptr;
			tail->next = newNode; // Point (old)tail next to new node, we know it's not empty as we checked before on n==1
			tail = newNode;
			size++;
			return;
		}
		Node<T>* oldNode = head;
		// We check if the number is closer to the start or to the end and then approach it by whatever side is closer
		if (n <= size / 2) {
			for (int i = 1; i < n - 1; i++) {
				oldNode = oldNode->next; // Closer to start, approach from head
			}
		}
		else {
			oldNode = tail;
			for (int i = size; i > n - 1; i--) {
				oldNode = oldNode->prev; // Closer to end, approach from tail
			}
		}

		newNode->next = oldNode->next; // Set the next node pointer to match the old node at n
		oldNode->next = newNode; // Set the old next node pointer to match the new node
		newNode->prev = oldNode; // Set the new node prev pointer to the old node at n
		newNode->next->prev = newNode; // Set the next node's prev pointer to point towards the new node
		size++;
	}
	void deleteNode(int n) {
		// If deleting the first node, point head to next, new head's prev pointer to null, then de-allocate memory for deleted node
		if (n == 1) {
			Node<T>* toDelete = head;
			head = head->next;
			if (head) {
				head->prev = nullptr;
			}
			else {
				tail = nullptr;
			}
			delete toDelete;
			size--;
			return;
		}
		// If deleting the last node, point tail to prev, new tail's next pointer to null, then de-allocate memory for deleted node
		if (n == size) {
			Node<T>* toDelete = tail;
			tail = tail->prev;
			if (tail) {
				tail->next = nullptr;
			}
			else {
				head = nullptr;
			}
			delete toDelete;
			size--;
			return;
		}
		// We check if the number is closer to the start or to the end and then approach it by whatever side is closer
		Node<T>* toDelete = nullptr;
		if (n <= size / 2) {
			toDelete = head;
			for (int i = 1; i < n; i++) {
				toDelete = toDelete->next; // Closer to start, approach from head
			}
		}
		else {
			toDelete = tail;
			for (int i = size; i > n; i--) {
				toDelete = toDelete->prev; // Closer to end, approach from tail
			}
		}
		// Unlink nodes from it and delete it
		toDelete->prev->next = toDelete->next;
		toDelete->next->prev = toDelete->prev;
		delete toDelete;
		size--;
	}
	void insertAtHead(T x) {
		// If added to the front, point next to (old)head then head to new node, then prev to null as it is first element
		Node<T>* newNode = new Node<T>();
		newNode->data = x;
		newNode->next = head;
		newNode->prev = nullptr;
		if (head) head->prev = newNode; // If a previous head node existed, then point its prev towards new node
		if (!head) tail = newNode; // Else, this node is the first node so it will be both head and tail
		head = newNode;
		size++;
	}
	void insertAtTail(T x) {
		// If added to the back, point prev to (old)tail then tail to new node, then next to null as it is last element
		Node<T>* newNode = new Node<T>();
		newNode->data = x;
		newNode->next = nullptr;
		newNode->prev = tail;
		if (tail) tail->next = newNode; // If a previous tail node existed, then point its next towards new node
		if (!tail) head = newNode; // Else, this node is the first node so it will be both head and tail
		tail = newNode;
		size++;
	}

	void reverseList() {
		if (head == nullptr) return;

		Node<T>* current = head;
		Node<T>* prevNode = nullptr;
		// Switch tail and head
		tail = head;
		// For each element in the list, switch its prev and next pointers
		while (current) {
			prevNode = current->prev; // Store the current node's prev pointer
			current->prev = current->next;
			current->next = prevNode;

			if (!current->prev) { // If the previous node is null, it must be the head node
				head = current;
			}
			current = current->prev; // Traverse forwards, but front and back have been reversed
		}

	}
	void print() {
		Node<T>* traverser = head;
		std::cout << "List is: ";
		// Traverse the list printing the data on each node
		while (traverser != nullptr) {
			std::cout << traverser->data << " ";
			traverser = traverser->next;
		}
		std::cout << std::endl;
	}
	void reversePrint() {
		Node<T>* traverser = tail;
		std::cout << "Reverse list is: ";
		// Traverse the list backwards starting at tail printing the data on each node
		while (traverser != nullptr) {
			std::cout << traverser->data << " ";
			traverser = traverser->prev;
		}
		std::cout << std::endl;
	}
	void recursivePrint(Node<T>* node) {
		// Traverse the list printing the data on each node
		if (!node) return;
		std::cout << node->data << " ";
		recursivePrint(node->next);
	}
	void recursiveReversePrint(Node<T>* node) {
		// Traverse the list backwards starting at tail printing the data on each node
		if (!node) return;
		std::cout << node->data << " ";
		recursiveReversePrint(node->prev);
	}
};