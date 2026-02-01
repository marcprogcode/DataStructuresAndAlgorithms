# Data Structures

## Array
`int A[x]` $\rightarrow$ x is the size of the array.

You have to provide a size beforehand that will allocate memory to store x copies of the data type in sequence. This wastes memory on non-full list.

```text
      Memory is contiguous
+---+---+---+---+---+---+---+---+
| 0 | 1 | 2 | 3 |   |   |   |   |  <-- allocated size (x)
+---+---+---+---+---+---+---+---+
  ^               ^
  |               |
 Used Data      Unused / Wasted Space
```

If you exceed this limit you have to copy the data to a new (usually 2x the size) array.

**Calculating the position of an element is simple:**
`Location of first + index * data_size`

**Memory:**
*   Fixed
*   With unused space
*   Must be continuous

**Overall:**
*   Constant time to access element: **O(1)**
*   Time to insert is linear (end is O(1)): **O(n)**
*   Remove element is linear: **O(n)**
*   Add element is slow but linear: **O(n)**

---

## Linked List
```c
struct Node {
  int data;
  Node* link;
}
```

No size limit so lists are dynamic. You create a head node that will contain data and a pointer to the next node.

**Head** $\rightarrow$ **[2 | $\cdot$]** $\rightarrow$ **[4 | $\cdot$]** $\rightarrow$ **[6 | Null]**

To add/remove an item, you change the pointers beforehand to point towards the new element and then point to the next.

To access an element you have to follow the chain to find it.

**Complexity:**
*   Time to access elements is linear: **O(n)**
*   Time to insert, remove or add: **O(n)** (At beginning **O(1)**)

**Memory:** No unused memory but extra memory for pointers. Can be separated by blocks.

---

## Doubly Linked List
```c
struct Node {
  int data;
  Node* next;
  Node* prev;
}
```

Same as Linked List but with backlinks. Allows traversal in both directions (forward and backward).

**Head** $\rightarrow$ **[ Null | 2 | $\cdot$ ]** $\leftrightarrow$ **[ $\cdot$ | 4 | $\cdot$]** $\leftrightarrow$ **[ $\cdot$ | 3 | Null ]**

To add an item or remove, you must update pointers on *both* links (prev and next). It is slightly more complex than a singly linked list.

**Overall:**
*   Time to access element is linear: **O(n)**
*   Time to insert or remove (if node is known): **O(1)**
*   Add element at start/end (with tail pointer): **O(1)**

**Memory:** No unused memory (blocks), but higher overhead per node because you store 2 pointers instead of 1.

## Stack (ADT)
```text
    +     +
    |     |  
    +-----+
    |  1  |  <-- Top
    +-----+
    |  5  |
    +-----+
```
A stack is an abstract data type that follows the **last-in-first-out (LIFO)** order. This means that elements can only be inserted or deleted from the top.
One property of stacks is that they can easily reverse a list, by simply placing in the stack, then retrieving it, it will be reversed, as you'll first take out the (previously) last node, and end up on the (previously) first node.
**4 basic operations can be performed on a stack:**

1.  **push(x):** Inserts x at the top of the stack
2.  **pop():** Removes the element at the top
3.  **top():** Return the element at the top
4.  **isEmpty()**: Return true if stack is empty

All of these operations have a time complexity of **O(1)**.
## Queue (ADT)
```text
```
A queue is an abstract data type just like a stack, but instead of LIFO, it's order is **first-in-first-out (FIFO)**. In this case, operations can only be done to the first element added to the Queue.
**WIP**