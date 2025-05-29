#include <iostream>
// clang-format off
struct Listnode {
    int val;
    Listnode* next;
    Listnode(int x) : val{x}, next{nullptr} {}
};
// clang-format on
void insert(Listnode* cur_node, Listnode* new_node) {
    new_node->next = cur_node->next;
    cur_node->next = new_node;
}
void remove(Listnode* cur_node) {
    if (cur_node == nullptr)
        return;
    Listnode* temp = cur_node->next;
    if (temp == nullptr)
        return;
    cur_node->next = temp->next;
    delete temp;
}
Listnode* access(Listnode* head, int index) {
    for (int i = 0; i < index; i++) {
        if (head->next == nullptr)
            return nullptr;
        head = head->next;
    }
    return head;
}
int find(Listnode* head, int target) {
    int index = 0;
    while (head != nullptr) {
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}
void output_list(Listnode* head) {
    Listnode* ptr = head;
    while (ptr != nullptr) {
        std::cout << ptr->val << ' ';
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

int main() {
    Listnode* head;
    Listnode* n0 = new Listnode(1);
    Listnode* n1 = new Listnode(1);
    Listnode* n2 = new Listnode(4);
    Listnode* n3 = new Listnode(5);
    Listnode* n4 = new Listnode(1);
    Listnode* n5 = new Listnode(4);
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    output_list(n0);
    Listnode* n7 = new Listnode(8);
    head = n0;
    std::cout << find(head, 5) << std::endl;
    insert(n2, n7);
    output_list(n0);
    remove(n1);
    output_list(n0);
}