#include <iostream>
#include <string>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void deleteNode(struct Node **head_ref, struct Node *to_delete) {
    if (*head_ref == nullptr || to_delete == nullptr) {
        return;
    }
    if (*head_ref == to_delete) {
        *head_ref = to_delete->next;
    }
    if (to_delete->next != nullptr) {
        to_delete->next->prev = to_delete->prev;
    }
    if (to_delete->prev != nullptr) {
        to_delete->prev->next = to_delete->next;
    }
    delete (to_delete);
}

void deleteNodeAtGivenPos(struct Node **head_ref, int pos) {
    if (*head_ref == nullptr || pos <= 0) {
        return;
    }
    struct Node *current = *head_ref;
    for (int i = 0; current != nullptr && i < pos; i++) {
        current = current->next;
    }
    if (current == nullptr) {
        return;
    }
    deleteNode(head_ref, current);
}

void insertAfter(Node *prev_node, int new_data) {
    if (prev_node == nullptr) {
        return;
    }
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != nullptr) {
        new_node->next->prev = new_node;
    }
}

void insertNodeAtGivenPos(struct Node **head_ref, int n, int new_data) {
    if (*head_ref == nullptr || n <= 0) {
        return;
    }
    struct Node *current = *head_ref;
    for (int i = 0; current != nullptr && i < n; i++) {
        current = current->next;
    }
    if (current == nullptr) {
        return;
    }
    insertAfter(current, new_data);
}

void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = new Node;
    new_node->data = new_data;
    new_node->prev = nullptr;
    new_node->next = (*head_ref);
    if ((*head_ref) != nullptr) {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

void append(Node **head_ref, int new_data) {
    Node *new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = nullptr;
    if (*head_ref == nullptr) {
        new_node->prev = nullptr;
        *head_ref = new_node;
        return;
    }
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

void reverse(Node **head_ref) {
    Node *temp = nullptr;
    Node *current = *head_ref;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != nullptr) {
        *head_ref = temp->prev;
    }
}

void printList(struct Node *head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
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
        if (str == "push_front") {
            push(&head, arg);
        } else if (str == "push_back") {
            append(&head, arg);
        } else if (str == "insert") {
            int val;
            std::cin >> val;
            insertNodeAtGivenPos(&head, val, arg);
        } else if (str == "remove") {
            deleteNodeAtGivenPos(&head, arg + 1);
        }
    }
    printList(head);
    reverse(&head);
    printList(head);
    return 0;
}
