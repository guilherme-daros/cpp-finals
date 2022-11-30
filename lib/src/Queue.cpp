#include "Queue.hpp"

template <class T>
void Queue<T>::push(T new_data) {
  Node<T>* tmp;
  if (length == 0) {
    tail = new Node<T>(new_data);
    head = tail;
  } else {
    head->prev = new Node<T>(new_data);
    tmp = head;
    head = head->prev;

    head->next = tmp;
  }
  length++;
}

template <class T>
T Queue<T>::pop() {
  T result;
  Node<T>* tmp;

  if (length == 0)
    result = {};
  else {
    tmp = tail->prev;
    result = tail->value;
    delete tail;
    tail = tmp;
    tail->next = 0;
    length--;
  }
  if (length == 0)
    tail = 0;

  return result;
}

template <class T>
Node<T>* Queue<T>::begin() {
  return head;
}

template <class T>
Node<T>* Queue<T>::end() {
  return tail;
}

template <class T>
bool Queue<T>::isEmpty() {
  return length == 0 ? true : false;
}