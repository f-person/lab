#include <iostream>

template <typename T>
struct Node {
  T data;
  Node<T>* link;

  Node(T data) {
    this->data = data;
    this->link = NULL;
  }
};

// Linked list implementation of stack.
template <typename T>
class Stack {
 private:
  Node<T>* head;

 public:
  Stack() {}

  Stack(T data) { this->head = new Node<T>(data); }

  void push(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->link = this->head;
    this->head = newNode;
  }

  T get() { return this->head->data; }

  void pop() {
    Node<T>* temp = this->head;
    this->head = this->head->link;
    delete temp;
  }

  bool isEmpty() { return head == NULL; }

  // Prints the contents of stack in FILO order.
  void print() {
    Node<T>* node = head;
    while (node != NULL) {
      std::cout << node->data << " ";
      node = node->link;
    }

    std::cout << std::endl;
  }
};

int main() {
  Stack<int> stack;

  stack.push(123);
  stack.print();

  stack.push(32);

  stack.push(69);
  stack.print();

  stack.pop();
  stack.print();

  return 0;
}
