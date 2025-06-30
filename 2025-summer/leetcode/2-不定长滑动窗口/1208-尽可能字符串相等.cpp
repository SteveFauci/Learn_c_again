#include <string>
using namespace std;
class Solution {
  public:
    int equalSubstring(string s, string t, int maxCost) {
        int sz = s.size();
        int left = 0;
        int sum = 0;
        int ans = 0;
        for (int right = 0; right < sz; right++) {
            sum += abs(s[right] - t[right]);
            while (sum > maxCost) {
                sum -= abs(s[left] - t[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};