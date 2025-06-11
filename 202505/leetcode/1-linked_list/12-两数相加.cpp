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
        ListNode *ptr1 = l1, *ptr2 = l2;
        ListNode  new_head(0), *ptr = &new_head;
        if (!ptr1)
            return ptr2;
        if (!ptr2)
            return ptr1;
        int cache = 0;
        while (ptr1 && ptr2) {
            int sum = ptr1->val + ptr2->val + cache;
            if (!ptr->next) {
                ptr->next = new ListNode(sum % 10, nullptr);
                cache = sum/10;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            ptr = ptr->next;
        }
        while(ptr1){
            int sum = ptr1->val + cache;
            if (!ptr->next) {
                ptr->next = new ListNode(sum % 10, nullptr);
                cache = sum/10;
            }
            ptr1 = ptr1->next;
            ptr = ptr->next;
        }
        while(ptr2){
            int sum = ptr2->val + cache;
            if (!ptr->next) {
                ptr->next = new ListNode(sum % 10, nullptr);
                cache = sum/10;
            }
            ptr2 = ptr1->next;
            ptr = ptr->next;
        }
        if(cache){
            ptr->next = new ListNode(cache,nullptr);
        }
        return new_head.next;
    }
};