#include <vector>
using namespace std;

class Solution {
  public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> my_map(n, vector<int>(n, 0));
        vector<int> degree(n,0);
        int ans = 0;
        for (int i = 0; i < roads.size(); i++) {
            my_map[roads[i][0]][roads[i][1]] = 1;
            my_map[roads[i][1]][roads[i][0]] = 1;
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }
        for(int i = 0;i < n-1; i++){
            int temp = 0;
            for(int j = i+1;j < n; j++){
                if(my_map[i][j]==1){
                    ans = max(ans,degree[i]+degree[j]-1);
                }
                else{
                    ans = max(ans,degree[i]+degree[j]);
                }
            }
        }
        return ans;
    }
};