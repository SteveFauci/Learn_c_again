// clang-format off
struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// clang-format on
class Solution {
  public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode *odd = head, *even = head->next;
        ListNode* even_head = even;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            if (odd->next) {
                even->next = odd->next;
                even = even->next;
            } else
                even->next = nullptr;
        }
        odd->next = even_head;
        return head;
    }
};