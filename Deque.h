
#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
using namespace std;

class deque
{
private:
  int** blockmap;
  int size;
  //helpers go here
  
public:
  deque();
  ~deque();
  
  void pushfront(int insert);
  void popfront();
  int front();
  int back();
  bool empty();
  int size();
  operator[](int location);

  //accessors (public helpers) go here
  
} #endif //DEQUE_H
