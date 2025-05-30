// clang-format off
struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
//solution 1
class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
        ListNode *ptr = head;
        ListNode* temp = head;
        if(!head)return nullptr;
        while(ptr->next){
            temp = ptr->next;
            ptr->next = temp->next;
            temp->next = head;
            head = temp;
        }
        return head;
    }
};
// solution2: Using stack