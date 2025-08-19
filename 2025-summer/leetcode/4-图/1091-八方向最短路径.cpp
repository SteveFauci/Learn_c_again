#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    const int dx[8] = {1,1,1,0,0,-1,-1,-1};
    const int dy[8] = {1,0,-1,1,-1,1,0,-1};
    struct QNode{
        int x,y,step;
        QNode(int x1,int y1,int s):x(x1),y(y1),step(s){}
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<QNode> my_que;

        if(grid[0][0] || grid[m-1][n-1])return -1;

        my_que.emplace(QNode(0,0,1));
        while(!my_que.empty()){
            QNode temp = my_que.front();
            my_que.pop();
            visited[temp.x][temp.y] = true;
            for(int i = 0; i < 8; i++){
                int x = temp.x + dx[i];
                int y = temp.y + dy[i];
                if(x < 0 || y < 0 || x >= m || y >= n) continue;
                if(visited[x][y] || grid[x][y]) continue;
                my_que.emplace(QNode(x,y,temp.step+1));
                visited[x][y] = true;
                if(visited[m-1][n-1]) return temp.step + 1; 
            }
        }
        return -1;
    }
};
#include<iostream>
int main() {
    Solution a;
    vector<vector<int>> grid = {
        {0, 0, 1, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    int res = a.shortestPathBinaryMatrix(grid);
    cout << res << endl;
}