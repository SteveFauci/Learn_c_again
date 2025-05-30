// clang-format off
struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// clang-format on
// 这个题很像那个奇迹的位运算。把链表弄成环再移动就行了
class Solution {
  public:
    ListNode* rotateRight(ListNode* head, int k) {
        int sz = getSize(head);
        if (sz == 0 || sz == 1)
            return head; // list为空或1个node直接返回头
        k %= sz;
        if (k == 0)
            return head; // 转一圈回来直接返回头

        ListNode* head2 = head; // 让head2指向新头
        for (int i = 0; i < sz - k; i++) {
            head2 = head2->next;
        }
        ListNode* ptr = head2; // 借助ptr把链表连接成环
        for (int i = 0; i < sz; i++) {
            if (!ptr->next)
                ptr->next = head;
            if (ptr->next == head2)
                ptr->next = nullptr;
            ptr = ptr->next;
        }
        return head2;
    }

  private:
    int getSize(ListNode* head) {
        if (!head)
            return 0;
        return 1 + getSize(head->next); // 这个递归可能会栈溢出
    }
};

// 优化建议：下面的思路比我的清晰多了。先一次遍历，找到tail节点并得到sz，把tail连到头节点，再一次遍历得到newtail，然后断链就好了。
class Solution2 {
  public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next)
            return head; // 空链表或只有一个节点直接返回

        // 计算链表长度并找到尾节点
        int       sz = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            sz++;
        }

        k %= sz;
        if (k == 0)
            return head; // 不需要旋转

        // 找到新的尾节点（即第 sz - k - 1 个节点）
        ListNode* newTail = head;
        for (int i = 0; i < sz - k - 1; i++) {
            newTail = newTail->next;
        }

        // 新的头节点是 newTail->next
        ListNode* newHead = newTail->next;
        newTail->next = nullptr; // 断开链表
        tail->next = head;       // 连接成环
        return newHead;
    }
};