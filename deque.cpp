/**
 * @file deque.cpp
 * @author Tristan Riley and Jesse Doescher
 * @date 2023-11-27
 * @brief Implementation file containing the definitions for the member functions of the `Deque` class.
 */

#include <iostream>
#include "deque.h"

Deque::Deque() {
    blockSize = 10;
    frontBlock = backBlock = 0;
    frontIndex = backIndex = -1;
    capacity = 1;
    blockmap = new int*[capacity];
    blockmap[0] = new int[blockSize];
}

Deque::~Deque() {
    for (int i = 0; i < capacity; ++i) {
        delete[] blockmap[i];
    }
    delete[] blockmap;
}

void Deque::push_front(int value) {
    if (frontIndex == -1) {
        frontIndex = backIndex = blockSize - 1;
    } else if (frontIndex == 0) {
        if (frontBlock == 0) {
            // If the front block is already at the beginning and full, resize the deque
            resizeDeque();
        }
        blockmap[--frontBlock] = new int[blockSize];
        frontIndex = blockSize - 1;
    } else {
        --frontIndex;
    }
    blockmap[frontBlock][frontIndex] = value;
}


void Deque::pop_front() {
  // Check to see if the deque is empty
    if (empty()) {
        std::cout << "Deque is empty. Cannot pop_front()." << std::endl;
        return;
    }

    if (frontIndex == blockSize - 1) {
        // If the current block is at the end, delete it and move to the next block
        delete[] blockmap[frontBlock];
        if (frontBlock == backBlock) {
            // If there is only one block left after deletion, reset the indices
            frontIndex = backIndex = -1;
        } else {
            ++frontBlock;
            frontIndex = 0;
        }
    } else {
        // Otherwise, move to the next element in the current block
        ++frontIndex;
    }
}


void Deque::push_back(int value) {
    if (backIndex == -1) {
        frontIndex = backIndex = 0;
    } else if (backIndex == blockSize - 1) {
        if (backBlock == capacity - 1) {
            // If the back block is at the end and full, resize the deque
            resizeDeque();
        }
        blockmap[++backBlock] = new int[blockSize];
        backIndex = 0;
    } else {
        ++backIndex;
    }
    blockmap[backBlock][backIndex] = value;
}


void Deque::pop_back() {
  // Check if deque is empty
    if (empty()) {
        std::cout << "Deque is empty. Cannot pop_back()." << std::endl;
        return;
    }

    if (backIndex == 0) {
        // If the current block is at the beginning, delete it and move to the previous block
        delete[] blockmap[backBlock];
        if (backBlock == frontBlock) {
            // If there is only one block left after deletion, reset the indices
            frontIndex = backIndex = -1;
        } else {
            --backBlock;
            backIndex = blockSize - 1;
        }
    } else {
        // Otherwise, move to the previous element in the current block
        --backIndex;
    }
}


int Deque::front() {
  // Check if deque is empty
    if (empty()) {
        std::cout << "Deque is empty. No front element." << std::endl;
        return -1; // Returning a default value (assuming int type) when deque is empty
    }

    return blockmap[frontBlock][frontIndex];
}


int Deque::back() {
  // Check if deque is empty
    if (empty()) {
        std::cout << "Deque is empty. No back element." << std::endl;
        return -1; // Returning a default value (assuming int type) when deque is empty
    }

    return blockmap[backBlock][backIndex];
}


bool Deque::empty() {
    return frontIndex == -1;
}

/*
void Deque::is_empty(){
  if (Deque::empty() == 1) {
    std::cout << "Yes! The deque is empty." << std::endl;
  }

  else {std::cout << "No! The deque is not empty" << std::endl;}
}
*/


int Deque::size() {
    if (empty()) {
        return 0; // If the deque is empty, return 0
    }

    int frontBlockSize = (frontBlock == backBlock) ? (backIndex - frontIndex + 1) : (blockSize - frontIndex);
    int backBlockSize = (backBlock - frontBlock - 1) * blockSize + backIndex + 1;

    return frontBlockSize + backBlockSize;
}


int Deque::operator[](int index) {
    if (index < 0 || index >= size()) {
        std::cout << "Index out of range." << std::endl;
        return -1; // Returning a default value for out-of-range access
    }

    int block = (frontBlock + (index + frontIndex) / blockSize) % capacity;
    int idx = (frontIndex + index) % blockSize;

    // Adjust index for negative values or wrap-around
    if (idx < 0) {
        idx += blockSize;
        block = (block - 1 + capacity) % capacity;
    }

    return blockmap[block][idx];
}




void Deque::resizeDeque() {
    int newCapacity = capacity * 2;  // Double the capacity

    // Create a new blockmap with the increased capacity
    int** newBlockmap = new int*[newCapacity];

    // Copy existing elements to the new blockmap
    for (int i = 0; i < capacity; ++i) {
        newBlockmap[i] = blockmap[i];
    }

    // Delete the old blockmap
    delete[] blockmap;



    // Update capacity and assign the new blockmap
    capacity = newCapacity;
    blockmap = newBlockmap;
}