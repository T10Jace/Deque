#include <iostream>
using namespace std;
#include "Deque.h"

deque::deque()
{
  blockmap = new int*[5];
  ptrsize = 5;
  
  int i = 0;
  while (i < 5)
    {
      blockmap[i] = new int 8;
      i++;
    }
  size = 0;
}

deque::~deque()
{
  int i = 0;
  while (i < ptrsize)
    {
      delete blockmap[i];
      i++;
    }
  delete blockmap;

  size = 0;
  ptrsize = 0;
}

void deque::expand()
{
  int holdsize = ptrsize;
  int* hold = new int*[holdsize];

  //Copy blockmap* to Hold & delete blockmap;
  int i = 0;
  while (i < holdsize)
    {
      hold[i] = blockmap[i];
      i++;
    }
  delete blockmap;

  //Recreate Blockmap* and replace its pointers
  ptrsize += 1;
  blockmap = new int*[ptrsize];

  i = 0;
  while (i < holdsize)
    {
      blockmap[i] = hold[i];
      i++;
    }
  delete hold;
  
  return;
}

void deque::pushfront(int insert)
{

}

void deque::popfront()
{

}

int deque::front()
{

}

int deque::back()
{

}

bool deque::empty()
{

}

int deque::size()
{

}

deque::operator[](int location)
{

}
