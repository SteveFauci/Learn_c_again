#include<vector>
#include<algorithm>
using namespace std;
class Solution2294 {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int fast = 0,slow = 0;
        int cnt = 1;
        while(fast<sz){
            if(nums[slow]+k>=nums[fast])fast++;
            else{cnt++;slow=fast;}
        }
        return cnt;
    }
};
class Solution2966 {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int sz = nums.size();
        for(int i = 0;i<sz;i+=3){
            vector<int> temp(3);
            temp[0] = nums[i];
            temp[1] = nums[i+1];
            temp[2] = nums[i+2];
            if(temp[2]-temp[0]>k)return {};
            ans.push_back(temp);
        }
        return ans;
    }
};