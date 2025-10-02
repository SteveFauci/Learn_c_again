#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz = digits.size();
        digits[sz-1]++;
        for(int i = sz - 1; i > 0; i--){
            if(digits[i] >= 10){digits[i]-=10;digits[i-1]+=1;}
        }
        if(digits[0]>=10){
            digits[0]-=10;
            vector<int> ans(sz+1);
            ans[0] = 1;
            for(int i = 0; i < sz; i++){
                ans[i+1] = digits[i];
            }
            return ans;
        }
        return digits;
    }
};