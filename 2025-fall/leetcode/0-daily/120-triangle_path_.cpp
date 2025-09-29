#include <bits/stdc++.h>
using namespace std;
// down or right
// [
// [2],
// [3,4],
// [6,5,7],
// [4,1,8,3],
// [4,2,3,5,6]
// ]
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz = triangle.size();
        vector<int> dp(sz,0);
        for(int i = 0; i < sz; i++){
            dp[i] = triangle[sz-1][i];
        }
        for(int i = sz - 2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                dp[i] = triangle[i][j] + min(dp[i],dp[i+1]);
            }
        }
        return dp[0];
    }
};
class Solution01 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz = triangle.size();
        vector<vector<int>> dp(sz,vector<int>(sz,0));
        for(int i = 0; i < sz; i++){
            dp[sz-1][i] = triangle[sz-1][i];
        }
        for(int i = sz - 2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
// 贪心算法是错的，局部最优不是全局最优
class SolutionWA {
  public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz = triangle.size();
        int currSum = triangle[0][0];
        int left, right, pos = 0, layer = 0;
        while (layer < sz - 1) {
            left = triangle[layer + 1][pos];
            right = triangle[layer + 1][pos+1];
            currSum += min(left,right);
            left < right ? pos = pos : pos = pos+1;
            layer++;
        }
        return currSum;
    }
};