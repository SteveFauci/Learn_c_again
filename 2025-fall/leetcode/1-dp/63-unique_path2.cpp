#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0])return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1])return 0;

        vector<vector<unsigned long long>> dp(m, vector<unsigned long long>(n, 0));
        for(int i = m-1; i >= 0; i--){
        if(obstacleGrid[i][n-1])break;
            dp[i][n-1] = 1;
        }
        for(int i = n-1; i >= 0; i--){
            if(obstacleGrid[m-1][i])break;
            dp[m-1][i] = 1;
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if(obstacleGrid[i][j]){dp[i][j] = 0;continue;}
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};