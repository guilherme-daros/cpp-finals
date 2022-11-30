#include "Node.hpp"

#pragma once

template <class T>
class Queue {
  Node<T>* head;
  Node<T>* tail;

 public:
  int length;
  Queue() {
    head = 0;
    tail = 0;
    length = 0;
  }

  ~Queue() {
    Node<T>* cursor = head;
    while (head) {
      cursor = cursor->next;
      delete head;
      head = cursor;
    }
    head = 0;  // Officially empty
    tail = 0;
    length = 0;
  }
  void push(T new_data);
  T pop();
  Node<T>* begin();
  Node<T>* end();
  bool isEmpty();
};
