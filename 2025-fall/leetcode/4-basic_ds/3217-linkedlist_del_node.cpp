#include<vector>
#include<algorithm>
using namespace std;
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
    bool myBinSearch(vector<int>& nums, int key){
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] > key){r = mid - 1;}
            else if(nums[mid] < key){l = mid + 1;}
            else if(nums[mid] == key){return true;}
        }
        return false;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(), nums.end());
        ListNode newhead(0);
        newhead.next = head;
        ListNode *fast = &newhead, *slow = &newhead;
        while(fast->next){
            if(myBinSearch(nums, fast->next->val)){
                fast = fast->next;
                slow->next = fast->next;
            }else{
                fast = fast->next;
                slow = slow->next;
            }
        }
        return newhead.next;
    }
};