#include <iostream>

template <typename T>
struct Node {
  T data;
  Node* link;

  Node<T>(T data) {
    this->data = data;
    this->link = NULL;
  }
};

template <typename T>
class LinkedList {
 private:
  Node<T>* start;
  int length;

 public:
  LinkedList<T>(T data) {
    this->start = new Node<T>(data);
    this->length = 1;
  }

  void push(T data) {
    Node<T>* node = start;
    while (node->link != NULL) {
      node = node->link;
    }
    node->link = new Node<T>(data);

    length++;
  }

  T get(int position) {
    int index = 0;
    Node<T>* node = start;
    while (index < position) {
      node = node->link;
      index++;
    }

    return node->data;
  }

  void insert(int position, T data) {
    Node<T>* new_node = new Node<T>(data);

    if (position > 0) {
      Node<T>* node = start;
      int index = 0;
      while (index < position - 1) {
        node = node->link;
        index++;
      }

      Node<T>* next_node = node->link;

      new_node->link = next_node;
      node->link = new_node;
    } else {
      new_node->link = start;
      this->start = new_node;
    }

    length++;
  }

  void remove(int position) {
    int index = 0;

    if (position > 0) {
      Node<T>* node_before_deleted_node = start;
      while (index < position - 1) {
        node_before_deleted_node = node_before_deleted_node->link;
        index++;
      }

      Node<T>* node_after_deleted_node = node_before_deleted_node->link->link;
      delete node_before_deleted_node->link;
      node_before_deleted_node->link = node_after_deleted_node;

    } else {
      Node<T>* next_node = this->start->link;
      delete this->start;

      this->start = next_node;
    }

    length--;
  }

  int getLength() { return this->length; }

  ~LinkedList<T>() {
    Node<T>* node = this->start;
    do {
      Node<T>* next = node->link;
      delete node;
      node = next;
    } while (node->link != NULL);
    delete node;
  }
};

int main() {
  LinkedList<int> list(0);

  for (int i = 1; i <= 10000; i++) {
    list.push(i);
  }

  for (int i = 0; i < list.getLength(); i++) {
    std::cout << list.get(i) << " ";
  }

  std::cout << std::endl;

  return 0;
}
