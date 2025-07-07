#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> visited;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        visited.resize(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                ans++;
                dfs(isConnected, n, i);
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& M, int n, int i) {
        visited[i] = 1;
        for (int j = 0; j < n; j++){
            if(M[i][j]==1 && i!=j && visited[j]==0){
                visited[j] = 1;
                dfs(M,n,j);
            }
        }
    }
};