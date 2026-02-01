#include "QueueArray.h"
#include "QueueLinkedList.h"
#include <iostream>

int main() {
  QueueLinkedList<int> QueueLL;

  std::cout << "Queue is: " << QueueLL.isEmpty() << std::endl;
  QueueLL.enqueue(1);
  QueueLL.enqueue(2);
  QueueLL.enqueue(3);
  QueueLL.enqueue(4);
  std::cout << "Queue is: " << QueueLL.peek() << std::endl;
  QueueLL.dequeue();
  std::cout << "Queue is: " << QueueLL.peek() << std::endl;
  QueueLL.dequeue();
  std::cout << "Queue is: " << QueueLL.peek() << std::endl;
  QueueLL.dequeue();
  std::cout << "Queue is: " << QueueLL.peek() << std::endl;
  QueueLL.dequeue();

  QueueArray<int> QueueArr(10);
  std::cout << "Queue is: " << QueueArr.isEmpty() << std::endl;
  QueueArr.enqueue(1);
  QueueArr.enqueue(2);
  QueueArr.enqueue(3);
  QueueArr.enqueue(4);
  std::cout << "Queue is: " << QueueArr.peek() << std::endl;
  QueueArr.dequeue();
  std::cout << "Queue is: " << QueueArr.peek() << std::endl;
  QueueArr.dequeue();
  std::cout << "Queue is: " << QueueArr.peek() << std::endl;
  QueueArr.dequeue();
  std::cout << "Queue is: " << QueueArr.peek() << std::endl;
  QueueArr.dequeue();
}
