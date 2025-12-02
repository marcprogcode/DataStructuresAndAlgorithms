// DoublyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
// All of the recursive implementations are slower and use much more memory (O(1) vs O(n)) but they are more intuitive and faster to code. Prefer iterative over recursive.
// The insert at n position and delete node has split traversal optimization using head/tail access based on the size of the list.

// TODO: TYPE AGNOSTIC IMPLEMENTATION
#include <iostream>

struct Node {
	int data;
	Node* next;
	Node* prev;
};

struct DoublyLinkedList {
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;
	// Deconstructor de-allocates memory from the heap after deletion of the list
	~DoublyLinkedList() {
		Node* current = head;
		// Traverse through the list
		while (current != nullptr) {
			Node* temp1;
			temp1 = current; // Saves the location of the current node
			current = current->next; // Traverses to the next node
			delete temp1; // Free the memory of this iteration's node
		}
	}

	void insert(int x, int n) {
		Node* newNode = new Node(); // Allocates space for new node

		newNode->data = x;

		// If added to the front, point next to (old)head then head to new node, then prev to null as it is first element
		if (n == 1) {
			newNode->next = head;
			newNode->prev = nullptr;
			if(head) head->prev = newNode; // If a previous head node existed, then point its prev towards new node
			else tail = newNode; // Else, this node is the first node so it will be both head and tail
			head = newNode;
			size++;
			return;
		}
		// If added to the back, point prev to (old)tail then tail to new node, then next to null as it is last element
		else if (n == size+1) { // Size +1 as the new length of the list is not accounted for yet
			newNode->prev = tail;
			newNode->next = nullptr;
			tail->next = newNode; // Point (old)tail next to new node, we know it's not empty as we checked before on n==1
			tail = newNode;
			size++;
			return;
		}
		Node* oldNode = head;
		// We check if the number is closer to the start or to the end and then approach it by whatever side is closer
		if (n <= size/2) {
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
			Node* temp = head;
			head = head->next;
			if (head) {
				head->prev = nullptr;
			}
			else {
				tail = nullptr;
			}
			delete temp;
			size--;
			return;
		}
		// If deleting the last node, point tail to prev, new tail's next pointer to null, then de-allocate memory for deleted node
		if (n == size) {
			Node* temp = tail;
			tail = tail->prev;
			if (tail) {
				tail->next = nullptr;
			}
			else {
				head = nullptr;
			}
			delete temp;
			size--;
			return;
		}
		// We check if the number is closer to the start or to the end and then approach it by whatever side is closer
		Node* toDelete = nullptr;
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
	void insertAtHead(int x) {
		// If added to the front, point next to (old)head then head to new node, then prev to null as it is first element
		Node* temp1 = new Node();
		temp1->data = x;
		temp1->next = head;
		temp1->prev = nullptr;
		if (head) head->prev = temp1; // If a previous head node existed, then point its prev towards new node
		if (!head) tail = temp1; // Else, this node is the first node so it will be both head and tail
		head = temp1;
		size++;
	}
	void insertAtTail(int x) {
		// If added to the back, point prev to (old)tail then tail to new node, then next to null as it is last element
		Node* temp1 = new Node();
		temp1->data = x;
		temp1->next = nullptr;
		temp1->prev = tail;
		if(tail) tail->next = temp1; // If a previous tail node existed, then point its next towards new node
		if(!tail) head = temp1; // Else, this node is the first node so it will be both head and tail
		tail = temp1;
		size++;
	}
	
	void reverseList() {
		if (head == nullptr) return;

		Node* current = head;
		Node* temp = nullptr;
		// Switch tail and head
		tail = head;
		// For each element in the list, switch its prev and next pointers
		while (current) {
			temp = current->prev; // Store the current node's prev pointer
			current->prev = current->next;
			current->next = temp;

			if (!current->prev) { // If the previous node is null, it must be the head node
				head = current;
			}
			current = current->prev; // Traverse forwards, but front and back have been reversed
		}
		
	}
	void print() {
		Node* temp1 = head;
		std::cout << "List is: ";
		// Traverse the list printing the data on each node
		while (temp1 != nullptr) {
			std::cout << temp1->data << " ";
			temp1 = temp1->next;
		}
		std::cout << std::endl;
	}
	void reversePrint() {
		Node* temp1 = tail;
		std::cout << "Reverse list is: ";
		// Traverse the list backwards starting at tail printing the data on each node
		while (temp1 != nullptr) {
			std::cout << temp1->data << " ";
			temp1 = temp1->prev;
		}
		std::cout << std::endl;
	}
	void recursivePrint(Node* node) {
		// Traverse the list printing the data on each node
		if (!node) return;
		std::cout << node->data << " ";
		recursivePrint(node->next); 
	}
	void recursiveReversePrint(Node* node) {
		// Traverse the list backwards starting at tail printing the data on each node
		if (!node) return;
		std::cout << node->data << " ";
		recursiveReversePrint(node->prev);
	}
};

int main() {
	DoublyLinkedList list;
	list.insertAtHead(4); // 4
	list.print(); // List is: 4
	list.insertAtHead(3);
	list.print(); // List is: 3 4
	list.insertAtHead(2);
	list.print(); // List is: 2 3 4
	list.insertAtHead(1);
	list.print(); // List is: 1 2 3 4
	list.insertAtTail(5);
	list.print(); // List is: 1 2 3 4 5
	list.insertAtTail(6);
	list.insert(7, 7);
	list.insert(0, 1);
	list.reversePrint(); // Reverse list is: 7 6 5 4 3 2 1 0
	std::cout << "List size: " << list.size << std::endl; // List size : 8
	list.recursivePrint(list.head); 
	std::cout << std::endl;
	list.recursiveReversePrint(list.tail);
	std::cout << std::endl;
	list.reverseList();
	list.print(); // List is : 7 6 5 4 3 2 1 0
	list.reversePrint(); // Reverse list is: 0 1 2 3 4 5 6 7
	list.deleteNode(1);
	list.print(); // List is: 6 5 4 3 2 1 0
	list.deleteNode(3);
	list.print(); // List is: 6 5 3 2 1 0
	list.deleteNode(5);
	list.print(); // List is: 6 5 3 2 0
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file