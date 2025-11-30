// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
// All of the recursive implementations are slower and use much more memory (O(1) vs O(n)) but they are more intuitive and faster to code. Prefer iterative over recursive.
#include <iostream>

template <typename T> // Type-agnostic implementation.
struct Node{
    T data;
    Node<T>* next;
};

template <typename T> // List and node shall share type.
struct LinkedList {
    // Deconstructor de-allocates memory from the heap after deletion of the list.
    ~LinkedList() {
        Node<T>* current;
        current = head;
        // Traverse through the list
        while (current != nullptr) {
            Node<T>* temp1; 
            temp1 = current; // Saves the location of the current node
            current = current->next; // Traverses to the next node
            delete temp1; // Free the memory of this iteration's node
        }
    }
    void insert(typename T x, int n) {
        Node<T>* temp1 = new Node<T>(); // Allocates space for new node

        temp1->data = x;
        temp1->next = nullptr;

        // If added to the front, point node to head then head to new node
        if (n == 1) {
            temp1->next = head;
            head = temp1;
            return;
        }
        // Traverse to the node before the position, point it to the new node, then point new node to node previously in the position
        Node<T>* temp2 = head;
        for (int i = 1; i < n - 1; i++) {
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
    }
    void deleteNode(int n) {
        // If deleting the first node, point head to next, then de-allocate memory for deleted node
        Node<T>* temp1 = head;
        if (n == 1) {
            head = head->next;
            delete temp1;
            return;
        }
        // Traverse to the node before the position, point it to the next node after deleted, then de-allocate memory for deleted node
        for (int i = 1; i < n - 1; i++) {
            temp1 = temp1->next;
        }
        Node<T>* temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
    void reverseList() {
        Node<T>* current, * prev, * next;
        current = head;
        prev = nullptr;
        // Traverse the tree while switching next node for prev node
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        // Finally, set head to the new first node
        head = prev;
    }
    void recursiveReverseList(Node<T>* p) {
        if (p->next == nullptr) {
            head = p;
            return;
        }
        recursiveReverseList(p->next);
        // After recursive call, traveling backwards
        p->next->next = p; // Set the next pointer of the next node to point towards the current node, so instead of pointing forward it points backwards
        p->next = nullptr; // Set the next pointer of this node to point towards null (asuming it's last, but it will get overwritten if there are any more backwards steps)
    }
    void recursiveReversePrint(Node<T>* p) {
        if (p == nullptr) return;
        recursiveReversePrint(p->next);        
        std::cout << p->data << " "; // After recursive call, traveling backwards
    }
    void recursivePrint(Node<T>* p) {
        if (p == nullptr) return;
        std::cout << p->data << " "; // Before recursive call, traveling forwards
        recursivePrint(p->next);
    }    
    void print() {
        Node<T>* temp = head;
        std::cout << "List is: ";
        // Traverse the list printing the data on each node
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    Node<T>* head = nullptr;
};

void TestLinkedList() {
    LinkedList<int> list;
    list.insert(1, 1); // 1
    list.print(); // Output: 1
    list.insert(2, 2); // 1, 2
    list.print(); // Output: 1, 2
    list.insert(3, 3); // 1, 2, 3
    list.print(); // Output: 1, 2, 3
    list.insert(4, 4); // 1, 2, 3, 4
    list.print(); // Output: 1, 2, 3, 4
    list.deleteNode(1); // 2, 3, 4
    list.print(); // Output: 2, 3, 4
    list.reverseList(); // 4, 3, 2
    std::cout << "Reversed list is: ";
    list.recursivePrint(list.head); // Output: 4, 3, 2
    std::cout << std::endl;
    std::cout << "Reversed reversed list is: ";
    list.recursiveReversePrint(list.head);  // Output: 2, 3, 4
    std::cout << std::endl;
    list.recursiveReverseList(list.head); // 2, 3, 4
    std::cout << "List is: ";
    list.recursivePrint(list.head); // Output: 2, 3, 4
    std::cout << std::endl;
}

int main() {
    TestLinkedList();

    return 0;
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
