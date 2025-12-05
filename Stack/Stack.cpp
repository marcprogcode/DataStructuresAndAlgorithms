// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StackArray.h"
#include "StackLinkedList.h"

std::string reverseString(std::string str) {
    StackArray<char> stack(int(str.length()));
    for (auto& c : str) {
        stack.push(c);
    }
    for (int i = 0; i < str.length(); i++) {
        str[i] = stack.top();
        stack.pop();
    }
    return str;
}

int main()
{
    StackArray<int> StackArr(10);
    int testSize = 11;
    for (int i = 0; i < testSize; i++) StackArr.push(i);
    std::cout << StackArr.top() << StackArr.isEmpty();
    for (int i = 0; i < testSize; i++) StackArr.pop();
    std::cout << StackArr.isEmpty() << std::endl;

    StackLinkedList<int> StackList;
    for (int i = 0; i < testSize; i++) StackList.push(i);
    std::cout << StackList.top() << StackList.isEmpty();
    for (int i = 0; i < testSize; i++) StackList.pop();
    std::cout << StackList.isEmpty() << std::endl;

    std::cout << reverseString("Hello!!!");

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
