#include <iostream>
#include <string>

class Node {
public:
    int data;
    Node *next;
};

void append(Node **head_ref, int new_data) {
    Node *new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = nullptr;
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
}

void insertAfter(Node **head_ref, int position, int new_data) {
    if (*head_ref == nullptr) {
        return;
    }
    Node *temp = *head_ref;
    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != nullptr && i < position; i++) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) {
        return;
    }
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = temp->next;
    temp->next = new_node;
}

void deleteNode(Node **head_ref, int position) {
    if (*head_ref == nullptr) {
        return;
    }
    Node *temp = *head_ref;
    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != nullptr && i < position; i++) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) {
        return;
    }
    Node *next = temp->next->next;
    delete (temp->next);
    temp->next = next;
}

void printList(Node *node) {
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    int size, commands;
    std::cin >> size >> commands;
    struct Node *head = nullptr;
    for (int i = 0; i < size; ++i) {
        int temp;
        std::cin >> temp;
        append(&head, temp);
    }
    for (int i = 0; i < commands; ++i) {
        std::string str;
        int arg;
        std::cin >> str;
        std::cin >> arg;
        if (str == "remove") {
            deleteNode(&head, arg);
        } else if (str == "insert") {
            int val;
            std::cin >> val;
            insertAfter(&head, val, arg);
        }
    }
    printList(head);
    return 0;
}
