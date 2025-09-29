#include <vector>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        dp[0] = matrix[0];
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == 0)  {dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i-1][j+1]);continue;}
                if(j == n-1){dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i-1][j-1]);continue;}
                dp[i][j] = matrix[i][j] + min(min(dp[i-1][j],dp[i-1][j-1]),dp[i-1][j+1]);
            }
        }
        int my_min = 2147483647;
        for(int i = 0; i < n; i++){
            my_min = min(my_min,dp[n-1][i]);
        }
        return my_min;
    }
};