#include <iostream>

template <typename T>
struct Node {
  T data;

  Node* prev;
  Node* next;

  Node(T data) {
    this->data = data;

    this->prev = NULL;
    this->next = NULL;
  }
};

template <typename T>
class DoublyLinkedList {
 private:
  Node<T>* start;
  int length;

 public:
  DoublyLinkedList(T data) { this->start = new Node<T>(data); }

  void push(T data) {
    Node<T>* node = start;
    while (node->next != NULL) {
      node = node->next;
    }

    Node<T>* newNode = new Node<T>(data);
    newNode->prev = node;
    node->next = newNode;

    this->length++;
  }

  T get(int index) {
    int i = 0;

    Node<T>* node = start;
    while (i < index) {
      node = node->next;
      i++;
    }

    return node->data;
  }

  int getLength() { return this->length; }
};

int main() {
  DoublyLinkedList<int> list(69);
  list.push(34);
  list.push(123);

  for (int i = 0; i < list.getLength(); i++) {
    std::cout << list.get(i) << std::endl;
  }

  return 0;
}
