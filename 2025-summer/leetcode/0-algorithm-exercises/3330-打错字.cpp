#include<string>
using namespace std;
class Solution {
public:
    int possibleStringCount(string word) {
        int sz = word.size();
        int left = 0;
        int cnt1 = 0;
        for (int right = 0; right < sz; right++) {
            if (word[right] != word[left]) {
                cnt1++;
                left = right;
            }
        }
        return sz - cnt1;
    }
};