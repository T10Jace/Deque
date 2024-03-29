/**
 * @file deque.h
* @author Tristan Riley and Jesse Doescher
 * @date 2023-11-27
 * @brief Header file defining the `Deque` class with its member variables and functions for deque operations.
 */

#ifndef DEQUE_H
#define DEQUE_H

class Deque {
private:
    int** blockmap;
    int blockSize;
    int frontBlock;
    int backBlock;
    int frontIndex;
    int backIndex;
    int capacity;

public:
    Deque();
    ~Deque();

    void push_front(int value);
    void pop_front();
    void push_back(int value);
    void pop_back();
    int front();
    int back();
    bool empty();
    int size();
    int operator[](int index);
    void is_empty();

private:
    void resizeDeque();
};

#endif // DEQUE_H