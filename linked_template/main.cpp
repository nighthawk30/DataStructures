#include <iostream>
#include "linked_list.h"

using namespace std;

int main()
{
  linked_list<int> list;
  for (int i = 0; i < 100; i++)
  {
    list.insert_at(i, 0);
  }
  list.print();
  return 0;
}
