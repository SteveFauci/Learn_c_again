// 明天再来看看一题多解 这个第一个解法是所谓的动态规划.
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
  public:
    int trap(vector<int>& height) {
        int n = height.size();
        int temp = 0;

        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> mini(n, 0);
        for (int i = 0; i < n; i++) {
            temp = max(height[i], temp);
            left[i] = temp;
        }
        temp = 0;
        for (int i = n - 1; i >= 0; --i) {
            temp = max(height[i], temp);
            right[i] = temp;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            mini[i] = min(right[i], left[i]);
            ans += (mini[i] - height[i]);
        }
        return ans;
    }
};