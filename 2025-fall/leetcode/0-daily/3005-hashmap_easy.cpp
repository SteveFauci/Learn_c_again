#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> my_map;
        for(auto i : nums){
            my_map[i]++;
        }
        int cnt = 0;
        int max = -1;
        for(auto i:my_map){
            if(i.second > max){
                max = i.second;
                cnt = 0;
                cnt += i.second;
            }else if(i.second == max){
                cnt += i.second;
            }
        }
        return cnt;
    }
};