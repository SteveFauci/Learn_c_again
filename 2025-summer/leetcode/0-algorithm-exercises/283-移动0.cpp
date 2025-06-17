#include <vector>
using namespace std;
class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int left = 0;
        for(int right = 0;right<size;++right){
            if(nums[right]!=0){nums[left]=nums[right];left++;}
        }
        while(left<size){nums[left]=0;left++;}
    }
};
