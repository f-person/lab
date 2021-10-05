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

 public:
  LinkedList<T>(T data) { this->start = new Node<T>(data); }

  void push(T data) {
    Node<T>* node = start;
    while (node->link != NULL) {
      node = node->link;
    }
    node->link = new Node<T>(data);
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
    // TODO: implement insert
  }

  void remove(int position) {
    // TODO: implement remove
  }

  // TODO: implement a destructor
};

int main() {
  LinkedList<int> list(6);
  list.push(9);

  std::cout << list.get(0) << std::endl << list.get(1) << std::endl;

  return 0;
}
