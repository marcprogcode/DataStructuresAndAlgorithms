#include "QueueArray.h"
#include "QueueLinkedList.h"
#include <iostream>

int main() {
  QueueLinkedList<int> QueueLL;

  std::cout << "Is queue empty?: " << QueueLL.isEmpty() << std::endl;
  QueueLL.enqueue(1);
  QueueLL.enqueue(2);
  QueueLL.enqueue(3);
  QueueLL.enqueue(4);
  std::cout << "Queue is: " << QueueLL.dequeue() << std::endl;
  std::cout << "Queue is: " << QueueLL.dequeue() << std::endl;
  std::cout << "Queue is: " << QueueLL.dequeue() << std::endl;
  std::cout << "Queue is: " << QueueLL.dequeue() << std::endl;

  QueueArray<int> QueueArr(10);
  std::cout << "Is queue empty?: " << QueueArr.isEmpty() << std::endl;
  QueueArr.enqueue(1);
  QueueArr.enqueue(2);
  QueueArr.enqueue(3);
  QueueArr.enqueue(4);
  std::cout << "Queue is: " << QueueArr.dequeue() << std::endl;
  std::cout << "Queue is: " << QueueArr.dequeue() << std::endl;
  std::cout << "Queue is: " << QueueArr.dequeue() << std::endl;
  std::cout << "Queue is: " << QueueArr.dequeue() << std::endl;
}
