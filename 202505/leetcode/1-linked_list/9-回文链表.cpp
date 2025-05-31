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
    bool isPalindrome(ListNode* head) {
        int n = getsize(head);
        ListNode*fast = head;
        ListNode*slow = head;
        for(int i = 0;i<(n+1)/2;i++){
            fast = fast->next;
        }
        fast = reverseList(fast);
        for(int i = 0;i<n/2;i++){
            if(fast->val != slow->val)return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr = head;
        ListNode* temp = head;
        if (!head)
            return nullptr;
        while (ptr->next) {
            temp = ptr->next;
            ptr->next = temp->next;
            temp->next = head;
            head = temp;
        }
        return head;
    }
    int getsize(ListNode *head){
        int i = 0;
        while(head){
            ++i;
            head = head->next;
        }
        return i;
    }
};
