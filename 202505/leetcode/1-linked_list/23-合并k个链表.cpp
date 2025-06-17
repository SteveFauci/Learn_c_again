// clang-format off
#include<vector>
using namespace std;
struct ListNode {
    int       val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto size = lists.size();
        if(size < 1) return nullptr;
        // 去除空链表
        vector<ListNode*> valid_lists;
        for (auto l : lists) if (l) valid_lists.push_back(l);
        lists = valid_lists;
        if (lists.empty()) return nullptr;
        // 合并
        ListNode *head = lists[0];
        for(int i = 0; i < lists.size() - 1; i++) {
            lstCat(getTail(lists[i]), lists[i + 1]);
        }
        head = sortList(head);
        return head;
    }
    ListNode* getTail(ListNode* head) {
        if (!head) return head;
        while (head->next) head = head->next;
        return head;
    }
    void lstCat(ListNode *prv_tail,ListNode * next_head){
        prv_tail->next = next_head;
    }
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