#pragma once
#include "DataStructures/List.hpp"
#include "DataStructures/Node.hpp"

template <class T>
class ListIterator {
  Node<T>* node;

 public:
  ListIterator(){};
  ListIterator(Node<T>* _node) : node(_node){};
  T operator*() { return node->data; };
  bool operator!=(const ListIterator& other) { return node != other.node; };
  ListIterator<T>& operator++() {
    node = node->next;
    return *this;
  };
};