#include<vector>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        auto size = nums.size();
        int sum = 0;
        vector<int> sums(size,-1);
        for(int i = 0;i<size;i++){
            sum+=nums[i];
            if(i<2*k)continue;
            sums[i-k]=sum/(2*k+1);
            sum-=nums[i-(2*k+1)+1];
        }
        return sums;
    }
};