#include<vector>
using namespace std;
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int sz =nums.size();
        int sum = 0;
        for(int i = sz-1; i >= 0; i--){
            for(int j = 0; j < i; j++){
                nums[j] = (nums[j]+nums[j+1])%10;
            }
        }
        return nums[0]%10;
    }
};