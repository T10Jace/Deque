/**
 * @file main.cpp
 * @author Tristan Riley
 * @date 2023-11-27
 * @brief main file that ultimately brings everything together to create the deque program.
 * 
 * This file gives a menu type of display in order to allow the user to choose what they would done with the data.
 */

#include <string>
#include <iostream>
#include <fstream>
#include <deque>
#include "deque.h"

using namespace std;

int main() {
    Deque<int> myDeque;

    // Adding elements to the deque
    myDeque.push_back(1);
    myDeque.push_back(2);
    myDeque.push_front(0);
    myDeque.push_front(-1);

    // Accessing elements using front() and back()
    cout << "Front element: " << myDeque.front() << endl;
    cout << "Back element: " << myDeque.back() << endl;

    // Accessing elements using operator[]
    cout << "Element at index 2: " << myDeque[2] << endl;

    // Removing elements from the deque
    myDeque.pop_back();
    myDeque.pop_front();

    // Checking size and if the deque is empty
    cout << "Size of deque: " << myDeque.size() << endl;
    cout << "Is deque empty? " << (myDeque.empty() ? "Yes" : "No") << endl;

    // Accessing elements after removal
    cout << "New front element: " << myDeque.front() << endl;
    cout << "New back element: " << myDeque.back() << endl;

    return 0;
}

