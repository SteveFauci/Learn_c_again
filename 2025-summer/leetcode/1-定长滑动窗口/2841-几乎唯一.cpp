#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        auto size = nums.size();
        unordered_map<int,int> my_map;
        long long max_n = 0;
        long long sum = 0;
        for(int i = 0;i<size;i++){
            sum += nums[i];//入
            my_map[nums[i]]++;
            if(i<k-1)continue;
            if(my_map.size()>=m)max_n = max(max_n,sum);//改
            my_map[nums[i-k+1]]--;
            if(my_map[nums[i-k+1]]==0)my_map.erase(nums[i-k+1]);//hash表元素数量为0要删掉，不然结果不对
            sum -= nums[i-k+1];//出
        }
        return max_n;
    }
};
int main(){
    Solution a;
    vector<int> nums = {1,1,1,3};
    int m = 2;
    int k = 2;
    cout << a.maxSum(nums, m, k);
}