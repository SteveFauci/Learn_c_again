#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int my_max = -1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    dp[i+1][j+1] = min(min(dp[i][j+1],dp[i][j]),dp[i+1][j]) + matrix[i][j] - '0';
                    my_max = max(my_max,dp[i+1][j+1]);
                }
            }
        }
        return my_max;
    }
};