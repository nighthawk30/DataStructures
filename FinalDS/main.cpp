#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <set>

using namespace std;

class node
{
 public:
  int data;
  node* left;
  node* right;
};

class oden
{
 public:
  double data;
  oden* next;
};

int product_evens(node* tree);
double linked_median(oden* head);
int linked_count(oden* head);
int* set_to_arr(set<int>& s);
void blaster(map<int, string> students);

int main()
{
  /*
  set<int> s = { 1, 2, 3, 4, 5 };
  int size = s.size();
  int* arr = set_to_arr(s);
  s.clear();

  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << endl;
  }
  delete[] arr;
*/
  /*
  oden* n1 = new oden;
  oden* n2 = new oden;
  oden* n3 = new oden;
  oden* n4 = new oden;
  oden* n5 = new oden;
  n1->data = 0;
  n2->data = 1;
  n3->data = 2;
  n4->data = 3;
  n5->data = 4;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = nullptr;
  n5->next = nullptr;
  cout << linked_median(n1) << endl;
   */
  int x = 5;
  int y = 7;
  int* p1 = &x;
  int* p2 = &y;
  *p1 = *p1 + x;
  p1 = p2;
  cout << *p1 + x << endl;
  cout << p1 << endl;
  cout << p1 + 2 << endl;
  return 0;
}

int* set_to_arr(set<int>& s)
{
  int* arr = new int[s.size()];
  int count = 0;
  for (set<int>::iterator it = s.begin(); it != s.end(); it++)
  {
    arr[count] = *it;
    count++;
  }
  return arr;
}

int product_evens(node* tree)
{
  int prod = 1;
  if (tree == nullptr)
  {
    return 1;
  }
  if (tree->data % 2 == 0)
  {
    prod *= tree->data;
  }
  prod *= product_evens(tree->right) * product_evens(tree->left);
  return prod;
}

int linked_count(oden* head)
{
  int size = 0;
  for (oden* p = head; p != nullptr; p = p->next)
  {
    size++;
  }
  return size;
}

double linked_median(oden* head)
{
  int length = linked_count(head);
  if (length % 2 == 0)
  {
    oden* l = head;
    oden* r = head;
    for (int i = 0; i < length / 2 - 1; i++)
    {
      l = l->next;
      r = l->next;
    }
    return ((r->data + l->data) / 2);
  }
  else
  {
    oden* p = head;
    for (int i = 0; i < length / 2; i++)
    {
      p = p->next;
    }
    return p->data;
  }
}

void blaster(map<int, string> students)
{
  for (map<int, string>::iterator it = students.begin(); it != students.end(); it++)
  {
    if (it->second == "Blaster")
    {
      cout << it->first << endl;
    }
  }
}