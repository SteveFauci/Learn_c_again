#include <algorithm>
#include <vector>
using namespace std;
class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> sum = {0, 0};
        int         n = cost.size();
        for (int i = 2; i <= n; i++) {
            sum.push_back(
                min(sum[i - 1] + cost[i - 1], sum[i - 2] + cost[i - 2]));
        }
        return sum[n];
    }
};