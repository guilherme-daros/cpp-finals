#pragma once
#include "Node.hpp"

template <class T>
class Queue {
  Node<T>* head;
  Node<T>* tail;
  int size;

 public:
  Queue() {
    head = 0;
    tail = 0;
    size = 0;
  }

  void push(T data) {
    Node<T>* newnode = new Node<T>(data);
    if (tail == 0) {
      head = newnode;
      tail = newnode;
    } else {
      tail->next = newnode;
      tail = tail->next;
    }
    size++;
  }

  T pop() {
    if (size == 0) {
      return 0;
    }
    Node<T>* temp = head;
    T ans = head->data;
    head = head->next;
    delete temp;
    size--;
    if (size == 0) {
      head == 0;
      tail = 0;
    }
    return ans;
  }

  int getSize() { return size; }

  bool isEmpty() { return size == 0; }
};