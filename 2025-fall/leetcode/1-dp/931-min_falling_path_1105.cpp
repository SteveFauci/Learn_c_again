#include<vector>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dpPrev(n, 0), dpCur(n, 0);
        dpPrev = matrix[0];
        dpCur = matrix[0];
        for(int i = 1; i < m; i++){             // 填第 i 行
            for(int j = 0; j < n; j++){         // 第 j 列的数字
                int minCost = 2147483647;
                for(int k = -1; k < 2; k++){    // 来自 上一行 第 j + k 列
                    int index = j + k;
                    if(index < 0 || index >= n)continue;
                    int cost = dpPrev[index] + matrix[i][j];
                    minCost = min(minCost, cost);
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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0] = matrix[0];
        for(int i = 1; i < m; i++){             // 填第 i 行
            for(int j = 0; j < n; j++){         // 第 j 列的数字
                int minCost = 2147483647;
                for(int k = -1; k < 2; k++){    // 来自 上一行 第 j + k 列
                    int index = j + k;
                    if(index < 0 || index >= n)continue;
                    int cost = dp[i - 1][index] + matrix[i][j];
                    minCost = min(minCost, cost);
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