//判断是否有环形链表，如果有返回入环点的指针。
struct ListNode {
    int       val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

class Solution {
  public:
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next)
            return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
