//题解有个递归法，有空可以去看看
// clang-format off
struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// clang-format off
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)return nullptr;
        while(head->val==val){
            if(!head->next)return nullptr;
            else head = head->next;//把所有头删了
        }
        ListNode* curr=head,*prev=head,*tail=head;
        if(curr->next) curr = curr->next;//快指针先走一步
        
        while(curr->next){
            if(curr->val==val){
                prev->next = curr->next;
                curr = curr->next;
            }else{
                prev = prev->next;
                curr = curr->next;
            }
        }
        if(!curr->next&&curr->val==val){
            prev->next=nullptr;
        }
        return head;
    }
};