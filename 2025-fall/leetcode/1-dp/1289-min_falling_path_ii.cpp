#include<vector>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dpPrev(n, 0), dpCur(n, 0);
        dpPrev = grid[0];
        dpCur = grid[0];
        for(int i = 1; i < m; i++){         // 填 dp 第 i 行
            for(int j = 0; j < n; j++){     // 填 dp 第 j 列
                int minCost = 2147483647;
                for(int k = 0; k < n; k++){
                    if(k == j)continue;
                    minCost = min(minCost, dpPrev[k] + grid[i][j]);
                }
                dpCur[j] = minCost;
            }
            dpPrev = dpCur;
        }
        int ans = 2147483647;
        for(int i = 0; i < n; i++){
            ans = min(ans, dpCur[i]);
        }
        return ans;
    }
};
class Solution0 {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0] = grid[0];
        for(int i = 1; i < m; i++){         // 填 dp 第 i 行
            for(int j = 0; j < n; j++){     // 填 dp 第 j 列
                int minCost = 2147483647;
                for(int k = 0; k < n; k++){
                    if(k == j)continue;
                    minCost = min(minCost, dp[i - 1][k] + grid[i][j]);
                }
                dp[i][j] = minCost;
            }
        }
        int ans = 2147483647;
        for(int i = 0; i < n; i++){
            ans = min(ans, dp[m - 1][i]);
        }
        return ans;
    }
};