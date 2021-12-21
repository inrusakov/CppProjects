#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

void moveNode(Node** new_r, Node** old_r) {
    Node* new_node = *old_r;
    *old_r = new_node->next;
    new_node->next = *new_r;
    *new_r = new_node;
}

Node* mergeLists(Node* first, Node* second, int size) {
    Node temp;
    Node* tail = &temp;
    temp.next = nullptr;
    int counter = size;
    while (counter != 0) {
        if (first == nullptr) {
            tail->next = second;
            break;
        } else if (second == nullptr) {
            tail->next = first;
            break;
        }
        if (first->data <= second->data) {
            moveNode(&(tail->next), &first);
        } else {
            moveNode(&(tail->next), &second);
        }
        tail = tail->next;
        counter--;
    }
    return (temp.next);
}

void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;
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

void printList(Node* node) {
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    Node* result = nullptr;
    Node* fst_list = nullptr;
    Node* snd_list = nullptr;
    int first, second;
    std::cin >> first >> second;
    for (size_t i = 0; i < first; i++) {
        int temp = 0;
        std::cin >> temp;
        append(&fst_list, temp);
    }
    for (size_t i = 0; i < second; i++) {
        int temp = 0;
        std::cin >> temp;
        append(&snd_list, temp);
    }
    result = mergeLists(fst_list, snd_list, first + second);
    printList(result);
    return 0;
}
