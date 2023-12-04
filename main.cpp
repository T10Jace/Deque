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
#include "deque.h"

using namespace std;

int main() {
    Deque deque;

    // Push elements to the front and back of the deque
    for (int i = 1; i <= 10; ++i) {
        deque.push_front(i); // Adds elements 5, 4, 3, 2, 1 to the front
        deque.push_back(i * 10); // Adds elements 10, 20, 30, 40, 50 to the back
    }

    // Output the front and back elements
    cout << "Front element: " << deque.front() << endl; // Should output: 10
    cout << "Back element: " << deque.back() << endl;   // Should output: 100

    // Output the size of the deque
    cout << "Size of deque: " << deque.size() << endl;   // Should output: 20

    // Access elements using operator[]
    cout << "Element at index 3: " << deque[3] << endl;  // Should output: 7
    cout << "Element at index 8: " << deque[8] << endl;  // Should output: 2
    cout << "Element at index 13: " << deque[13] << endl; // Should output: 40

    // Pop elements from the front and back of the deque
    deque.pop_front(); // Removes front element 10
    deque.pop_back();  // Removes back element 100

    // Output the front and back elements after popping
    cout << "Front element after popping: " << deque.front() << endl; // Should output: 9
    cout << "Back element after popping: " << deque.back() << endl;   // Should output: 90

    // Output the size of the deque after popping
    cout << "Size of deque after popping: " << deque.size() << endl;  // Should output: 18


    return 0;
}