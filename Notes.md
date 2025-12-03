# Data Structures

## Array
`int A[x]` $\rightarrow$ x is the size of the array.

You have to provide a size beforehand that will allocate memory to store x copy of the data type in sequence. This wastes memory on not empty list.

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
`Location of first + index * datasize`

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

To add an item or remove, you must update pointers on *both* links (prev and next). It is slightly more complex than a single list.

**Overall:**
*   Time to access element is linear: **O(n)**
*   Time to insert or remove (if node is known): **O(1)**
*   Add element at start/end (with tail pointer): **O(1)**

**Memory:** No unused memory (blocks), but higher overhead per node because you store 2 pointers instead of 1.