/**
 * @file main.cpp
* @author Tristan Riley and Jesse Doescher
 * @date 2023-11-27
 * @brief Example usage of the `Deque` class demonstrating various deque operations such as pushing, popping, accessing elements by index, etc.
 */

#include <string>
#include <iostream>
#include <fstream>
#include "deque.h"

using namespace std;

int main() {
    Deque deque;

    // Push elements to the front and back of the deque
    for (int i = 1; i <= 20; ++i) {
        deque.push_front(i); // Adds elements 20, 19, 17, 16, 15,..., 5, 4, 3, 2, 1 to the front
        deque.push_back(i * 10); // Adds elements 10, 20, 30, 40, ..., 200 to the back
    }

    // Output the front and back elements
    cout << "Front element: " << deque.front() << endl; // Should output: 20
    cout << "Back element: " << deque.back() << endl;   // Should output: 200

    // Output the size of the deque
    cout << "Size of deque: " << deque.size() << endl;   // Should output: 40

    // Access elements using operator[]
    cout << "Element at index 3: " << deque[3] << endl;  // Should output: 17
    cout << "Element at index 8: " << deque[8] << endl;  // Should output: 12
    cout << "Element at index 25: " << deque[25] << endl; // Should output: 60

    // Pop elements from the front and back of the deque
    deque.pop_front(); // Removes front element 20
    deque.pop_back();  // Removes back element 200

    // Output the front and back elements after popping
    cout << "Front element after popping: " << deque.front() << endl; // Should output: 19
    cout << "Back element after popping: " << deque.back() << endl;   // Should output: 190

    // Output the size of the deque after popping
    cout << "Size of deque after popping: " << deque.size() << endl;  // Should output: 38


    return 0;
}