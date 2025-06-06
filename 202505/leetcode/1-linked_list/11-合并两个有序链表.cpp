// 没做完
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* fast1 = list1,*slow1 = list1;
        ListNode* fast2 = list2,*slow2 = list2;
        if(!list1)return list2;
        if(!list2)return list1;
    }
};