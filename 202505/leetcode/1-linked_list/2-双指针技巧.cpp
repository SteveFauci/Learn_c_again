// 注意23行和24行要一步一个脚印，不然会ub
struct ListNode {
    int       val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};

class Solution {
  public:
    bool hasCycle(ListNode* head) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        if (ptr1 == nullptr)
            return false;
        while (true) {
            if (ptr1->next != nullptr)
                ptr1 = ptr1->next;
            else
                return false;

            if (ptr2->next != nullptr)
                if (ptr2->next->next != nullptr)
                    ptr2 = ptr2->next->next;
                else
                    return false;
            else
                return false;

            if (ptr1 == ptr2)
                return true;
        }
    }
};

////上面的对是对了，但是一堆if太石山了。改一下如下
bool hasCycle(ListNode* head) {
    if (!head || !head->next)
        return false;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true; // 上面的while直接判断fast就行了，如果没环肯定是fast先指向nullptr
    }
    return false;
}