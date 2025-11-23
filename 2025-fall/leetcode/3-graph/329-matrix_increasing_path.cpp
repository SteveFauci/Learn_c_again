#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    const int dx[4] = {0,1,0,-1};
    const int dy[4] = {1,0,-1,0};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<vector<pair<int,int>>>> adj(m,vector<vector<pair<int,int>>>(n));
        vector<vector<int>> inDeg(m,vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < 4; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]){
                        continue;
                    }
                    adj[i][j].push_back({x,y});
                    inDeg[x][y]++;
                }
            }
        }
        vector<vector<int>> dp(m,vector<int>(n,0));
        queue<pair<int,int>> myQue;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(inDeg[i][j] == 0){
                    myQue.push({i,j});
                    dp[i][j] = 1;
                }
            }
        } 
        while(!myQue.empty()){
            auto [x,y] = myQue.front();
            myQue.pop();
            for(auto[x2, y2] : adj[x][y]){
                dp[x2][y2] = max(dp[x][y] + 1, dp[x2][y2]);
                if(--inDeg[x2][y2] == 0){
                    myQue.push({x2,y2});
                }
            }
        }
        int ans = -1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};