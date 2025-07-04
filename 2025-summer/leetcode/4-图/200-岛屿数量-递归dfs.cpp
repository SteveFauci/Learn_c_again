#include<vector>
using namespace std;

class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size();i++){
            for(int j = 0; j < grid[0].size();j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int x2 = x + dx[i];
            int y2 = y + dy[i];
            if(x2<0 || x2>=grid.size() || y2<0 || y2>=grid[0].size()){
                continue;
            }if(grid[x2][y2]=='1'){
                dfs(grid,x2,y2);
            }
        }
    }
};