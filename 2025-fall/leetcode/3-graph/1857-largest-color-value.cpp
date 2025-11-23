#include<string>
#include<queue>
#include <vector>
using namespace std;
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> inDegree(n);
        vector<vector<int>> adj(n);
        for(auto e : edges){
            int u = e[0], v = e[1];
            inDegree[v]++;
            adj[u].push_back(v);
        }
        vector<vector<int>> dp(n, vector<int>(26,0));

        queue<int> myQue;
        for(int i = 0; i < n; i++){
            if(inDegree[i]==0) {
                myQue.push(i);
                dp[i][colors[i] - 'a'] ++;
            }
        }
        int cnt = 0;
        int ans = 0;
        while (!myQue.empty()) {
            int x = myQue.front(); myQue.pop();
            cnt++;
            for(int c = 0; c < 26; c++){
                ans = max(ans,dp[x][c]);
            }
            for(int y : adj[x]){
                for(int c = 0; c < 26; c++){
                    dp[y][c] = max(dp[x][c],dp[y][c]);
                }
                if(--inDegree[y] == 0) {
                    myQue.push(y);
                    dp[y][colors[y] - 'a'] ++;
                }
            }
        }
        if(cnt < n)return -1;
        return ans;
    }
};