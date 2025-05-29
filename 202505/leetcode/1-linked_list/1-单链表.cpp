class MyLinkedList {
  public:
    // 类里面用struct构建node
    struct node {
        int   val;
        node* next;
        node(int x) : val{x}, next{nullptr} {};
    };
    // 构造函数初始化链表
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    int get(int index) {
        if (index >= size || index < 0)
            return -1;
        node* ptr = head;
        while (index--) {
            ptr = ptr->next;
        }
        return ptr->val;
    }

    void addAtHead(int val) { // 没问题
        addAtIndex(0, val);
    }

    void addAtTail(int val) { // 没问题
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
            return;
        if (index == 0) {
            node* cur = new node(val);
            cur->next = head;
            head = cur;
            size++;
            return;
        }
        if (index == size) {
            node* ptr = head;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            node* cur = new node(val);
            ptr->next = cur;
            size++;
            return;
        }
        node* ptr = head;
        while (--index) {
            ptr = ptr->next;
        }
        node* cur = new node(val);
        cur->next = ptr->next;
        ptr->next = cur;

        size++;
    }

    void deleteAtIndex(int index) {
        node* ptr = head;
        if (head == nullptr || index < 0 || index >= size)
            return;
        if (index == 0) {
            node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }
        while (--index) {
            ptr = ptr->next;
        }
        node* temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
        size--;
    }

  private:
    int   size;
    node* head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
#include <iostream>
using namespace std;
int main() {
    MyLinkedList myLinkedList;

    // myLinkedList.addAtHead(1);
    // myLinkedList.addAtTail(3);
    // myLinkedList.addAtTail(4);
    myLinkedList.addAtIndex(2, 2); // 链表变成 1 -> 2 -> 3
    myLinkedList.deleteAtIndex(4); // 删除索引 1，链表变成 1 -> 3
    cout << myLinkedList.get(0) << ">";
    cout << myLinkedList.get(1) << ">";
    cout << myLinkedList.get(2) << ">";
    cout << myLinkedList.get(3) << ">";
    cout << myLinkedList.get(4) << endl;
    // //  cout << "get(1): " << myLinkedList.get(1) << endl; // 应该输出 3

    return 0;
}