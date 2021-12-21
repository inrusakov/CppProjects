#include <iostream>

struct Node {
    int data;
    struct Node* next;
    explicit Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

struct LinkedList {
    Node* head;
    explicit LinkedList(int top) {
        head = new Node(top);
    }
    LinkedList() {
        head = nullptr;
    }
    void reverse() {
        Node* current = head;
        Node *prev = nullptr, *next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    LinkedList reversedList() {
        LinkedList list;
        struct Node* temp = head;
        while (temp != nullptr) {
            list.push(temp->data);
            temp = temp->next;
        }
        return list;
    }

    void push(int data) {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void print() {
        struct Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void append(int new_data) {
        Node* new_node = new Node(new_data);
        Node* last = head;
        new_node->data = new_data;
        new_node->next = nullptr;
        if (head == nullptr) {
            head = new_node;
            return;
        }
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new_node;
    }
};

int main() {
    int size;
    std::cin >> size;
    int temp = 0;
    std::cin >> temp;
    LinkedList ll(temp);
    for (size_t i = 0; i < size - 1; i++) {
        int temp = 0;
        std::cin >> temp;
        ll.append(temp);
    }
    LinkedList new_l;
    new_l = ll.reversedList();
    new_l.print();
    return 0;
}
