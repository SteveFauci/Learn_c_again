#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        int left,right;
        int ans_l,ans_r;
        // odd
        for(int i = 0; i < sz; i++){
            left = right = i;
            while(left >=0 && right < sz && s[left] == s[right]){
                left--;right++;
            }
            // curr_len = r - l - 1
            if(right - left - 1 > ans_r - ans_l){
                ans_r = right;
                ans_l = left + 1; 
            }
        }
        // even
        for(int i = 0; i < sz - 1; i++){
            left = i;
            right = i + 1;
            while(left >=0 && right < sz && s[left] == s[right]){
                left--;right++;
            }
            // curr_len = r - l - 1
            if(right - left - 1 > ans_r - ans_l){
                ans_r = right;
                ans_l = left + 1; 
            }
        }
        return s.substr(ans_l,ans_r - ans_l);
    }
};