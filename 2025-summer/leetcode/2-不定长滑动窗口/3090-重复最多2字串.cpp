#include <string>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> my_map;
        int sz = s.size();
        int left = 0;
        int ans = 0;
        for (int right = 0; right < sz; right++) {
            char ch = s[right];
            my_map[ch]++;
            if (my_map[ch] > 2) {
                my_map[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};