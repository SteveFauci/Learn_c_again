#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> my_pq;
        for(auto i : nums){
            my_pq.push(i);
        }
        while(k--){
            my_pq.pop();
        }
        return my_pq.top();
    }
};