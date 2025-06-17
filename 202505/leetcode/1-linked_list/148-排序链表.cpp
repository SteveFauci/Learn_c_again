// clang-format off
struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //特判
        if(!head||!head->next)return head;
        ListNode* slow = head, *fast = head->next;
        //双指针打断
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *right = slow->next;
        slow->next = nullptr;
        ListNode *left = head;
        //递归
        left = sortList(left);
        right = sortList(right);
        //合并
        return mergeTwoLists(left,right);
    }
    // 下面的其实是 21-合并两个有序链表
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode new_head(0),*new_ptr = &new_head;
        while (ptr1&& ptr2) {
            if(ptr1->val<ptr2->val){
                new_ptr->next = ptr1;
                ptr1 = ptr1->next;
            }else if(ptr1->val>=ptr2->val){
                new_ptr->next = ptr2;
                ptr2 = ptr2->next;
            }
            new_ptr = new_ptr->next;
        }
        if(ptr1)new_ptr->next = ptr1;
        if(ptr2)new_ptr->next = ptr2;
        return new_head.next;
    }
};