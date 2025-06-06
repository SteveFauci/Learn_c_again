// 太繁琐了，以后来写
class MyLinkedList {
  public:
    struct ListNode {
        int       val;
        ListNode* prev;
        ListNode* next;
        ListNode(int x) : val{x}, prev{nullptr}, next{nullptr} {};
    };
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;
        ListNode* ptr = head;
        for (int i = 0; i < index; i++) {
            ptr = ptr->next;
        }
        return ptr->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
            return;
        if (index == 0) {
        } else if (index == size) {
        } else {
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;
        if (index == 0) {
        } else if (index == size) {
        } else {
        }
    }

  private:
    ListNode* head;
    ListNode* tail;
    int       size;
};
