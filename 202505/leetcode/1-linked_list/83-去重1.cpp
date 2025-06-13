// clang-format off
struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// 自己写的石山，思路是连接到下一个不同的，到最后还要指向nullptr
class Solution1 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode *fast = head,*slow = head;
        int temp1 = slow->val;
        while(fast){
            int temp2 = fast->val;
            if(temp1 != temp2){
                slow->next = fast;
                slow = slow->next;
                temp1 = slow->val;
            }
            fast = fast->next;
        }
        slow->next = nullptr;
        return head;
    }
};
//
class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode *ptr=head;
        while(ptr->next){
            if(ptr->next->val==ptr->val) ptr->next = ptr->next->next;
            else ptr = ptr->next;
        }
        return head;
    }
};