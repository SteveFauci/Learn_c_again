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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return reverseList(addTwoNumbers_(reverseList(l1), reverseList(l2)));
    }
    ListNode* addTwoNumbers_(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* l3 = new ListNode();
        ListNode* l3Head = l3;
        while (l1 || l2) {
            l3->val += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            carry = l3->val / 10;
            if (l1 || l2 || carry)
                l3->next = new ListNode(carry);
            l3->val %= 10;
            l3 = l3->next;
        }
        return l3Head;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* last = nullptr;
        ListNode* next = head;
        while (next) {
            head = next;
            next = next->next;
            head->next = last;
            last = head;
        }
        return head;
    }
};