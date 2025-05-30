struct ListNode {
    int       val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};
// clang-format off
class Solution {
  public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        if(!ptr1 || !ptr2)return nullptr;
        int flag1 = 0;
        int flag2 = 0;
        while (true) {
            if(ptr1==ptr2)return ptr1;//这里很像双指针前两次问题

            if (ptr1->next)ptr1=ptr1->next;
            else {ptr1 = headB;flag1++;}
            if (ptr2->next)ptr2=ptr2->next;
            else {ptr2 = headA;flag2++;}
            
            if(flag1==2&&flag2==2)return nullptr;
        }
    }
};