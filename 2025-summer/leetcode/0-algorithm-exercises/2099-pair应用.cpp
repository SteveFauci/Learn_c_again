#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> my_vec;
        int sz = nums.size();
        for(int i = 0;i < sz; i++){
            my_vec.push_back({nums[i],i});
        } 
        sort(my_vec.begin(),my_vec.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.first > b.first;
        });
        for(int i = 0; i < sz - k; i++){
            my_vec.pop_back();
        }
        sort(my_vec.begin(),my_vec.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.second < b.second;
        });
        sz = my_vec.size();
        vector<int> ans;
        for(int i = 0; i < sz; i++){
            ans.push_back(my_vec[i].first);
        }
        return ans;
    }
};