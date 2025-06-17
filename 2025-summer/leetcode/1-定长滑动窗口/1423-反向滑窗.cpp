#include <algorithm>
#include <vector>
using namespace std;
class Solution {
  public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 2147483647, sum = 0;
        int sz = cardPoints.size();
        int k2 = sz - k;
        int total = 0;
        for (int i = 0; i < sz; i++) {
            total += cardPoints[i];
            sum += cardPoints[i];
            if (i < k2 - 1)
                continue;
            ans = min(ans, sum);
            sum -= cardPoints[i - k2 + 1];
        }
        if(k == sz)return total;
        return total - ans;
    }
};