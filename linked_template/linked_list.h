#ifndef LINKED_TEMPLATE_LINKED_LIST_H
#define LINKED_TEMPLATE_LINKED_LIST_H

#include <iostream>

using namespace std;

//functions must be defined in .h for templated functions because it is only called when it is used
//can't be defined in a .cpp and .cpp aren't included
template <class T>
class node
{
 public:
  T data;
  node* next;
};

template <class T>
class linked_list
{
 public:
  linked_list()
  {
    head = nullptr;
    tail = nullptr;
    size = 0;
  }
  void insert(T new_data)
  {
    node<T>* new_node = new node<T>;
    new_node->data = new_data;
    new_node->next = nullptr;
    if (head == nullptr)
    {
      head = new_node;
      tail = new_node;
    }
    else
    {
      tail->next = new_node;
      tail = new_node;
      size++;
    }
  }
  void insert_at(T new_data, int index)
  {
    if (head == nullptr || index == size - 1)
    {
      insert(new_data);
    }
    else if (index < size && index >= 0)
    {
      node<T>* new_node = new node<T>;
      new_node->data = new_data;
      new_node->next = nullptr;
      if (index == 0)
      {
        node<T>* temp = head;
        head = new_node;
        head->next = temp;
      }
      else
      {
        node<T>* p = head;
        for (int i = 0; i < index - 1; i++)
        {
          p = p->next;
        }
        node<T>* temp = p->next;
        p->next = new_node;
        new_node->next = p;
      }
      size++;
    }
  }
  T at(int index)
  {//sec
    if (index < 0 || index > size)
    {
      return;
    }
    else
    {
      node<T>* p = head;
      for (int i = 0; i < index; i++)
      {
        p = p->next;
      }
      return p->data;
    }
  }
  void print()
  {
    for (node<T>* p = head; p != nullptr; p = p->next)
    {
      cout << p->data << endl;
    }
  }
  void print_reverse(node<T>* top)
  {
    print_reverse(top->next);
    if (top != nullptr)
    {
      cout << top->data << endl;
    }
  }
  void print_reverse()
  {
    print_reverse(head);
  }
  void remove_at(int index)
  {
    if (index < 0 || index >= size)
    {
      return;
    }
    if (index == 0)
    {
      node<T>* temp = head;
      head = temp->next;
      delete temp;
    }
    else
    {
      node<T>* p;
      int i = 0;
      for (p = head; p != nullptr; p = p->next)
      {
        if (i == index - 1)
        {
          node<T>* temp = p->next;
          p->next = temp->next;
          delete temp;
        }
        i++;
      }
      tail = p;
    }
    size--;
  }
  int get_size()
  {
    return size;
  }
 private:
  node<T>* head;
  node<T>* tail;
  int size;
};

#endif