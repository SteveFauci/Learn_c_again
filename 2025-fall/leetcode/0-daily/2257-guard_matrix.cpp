#include<vector>
using namespace std;
class Solution {
public:
    void print(vector<int>& point, vector<vector<int>> & grid, int & cnt){
        int x = point[0], y = point[1];
        y--;
        while(y >= 0 && (grid[x][y]==0 || grid[x][y] == 1)){
            if(grid[x][y]==0) cnt++;
            grid[x][y] = 1;
            y--;
        }

        x = point[0], y = point[1];
        y++;
        while(y < grid[0].size() && (grid[x][y]==0 || grid[x][y] == 1)){
            if(grid[x][y]==0) cnt++;
            grid[x][y] = 1;
            y++;
        }

        x = point[0], y = point[1];
        x--;
        while(x >= 0&& (grid[x][y]==0 || grid[x][y] == 1)){
            if(grid[x][y]==0) cnt++;
            grid[x][y] = 1;
            x--;
        }

        x = point[0], y = point[1];
        x++;
        while(x < grid.size() && (grid[x][y]==0 || grid[x][y] == 1)){
            if(grid[x][y]==0) cnt++;
            grid[x][y] = 1;
            x++;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        int cnt = 0;
        for(auto i : guards){
            grid[i[0]][i[1]] = 2;
        }
        for(auto i : walls){
            grid[i[0]][i[1]] = 2;
        }
        for(auto i : guards){
            print(i, grid, cnt);
        }
        return m * n - guards.size() - walls.size() - cnt;
    }
};