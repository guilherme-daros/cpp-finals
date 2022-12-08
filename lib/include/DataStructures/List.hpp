
#pragma once
#include <iostream>
#include "DataStructures/ListIterator.hpp"
#include "DataStructures/Node.hpp"
using namespace std;

template <class T>
class Linkedlist {
  Node<T>* head;
  uint32_t size;

 public:
  Linkedlist() {
    head = 0;
    size = 0;
  }

  void emplace_back(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == 0) {
      head = newNode;
      return;
    }
    Node<T>* temp = head;
    while (temp->next != 0) {
      temp = temp->next;
    }
    temp->next = newNode;
    size++;
  }

  T operator[](uint32_t index) {
    Node<T>* temp = head;
    uint32_t elem_index{0};

    if (head == 0 || index > size) {
      throw out_of_range("Index out of bounds");
    }

    while (temp != 0 && index < size) {
      if (elem_index == index) {
        return temp->data;
      }
      temp = temp->next;
      elem_index++;
    }
  }

  ListIterator<T> begin() { return ListIterator<T>(head); };
  ListIterator<T> end() {
    Node<T>* temp = head;

    if (head == 0) {
      return ListIterator<T>(head);
    }

    while (temp != 0) {
      temp = temp->next;
    }
    return ListIterator<T>(temp);
  };
};
