#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    struct QNode{
        int x,y;
        QNode(int x1,int y1):x(x1),y(y1){};
    };

    void bfs(vector<vector<int>>& grid,int x,int y,int &ans){
        int area = 0;
        grid[x][y] = 0;
        area++;

        stack<QNode> my_que;
        my_que.push(QNode(x,y));
        while(!my_que.empty()){
            QNode temp = my_que.top();
            my_que.pop();
            for(int i = 0; i < 4; i++){
                int x2 = temp.x + dx[i];
                int y2 = temp.y + dy[i];
                if(x2<0 || x2 >= grid.size() || y2<0 || y2 >=grid[0].size()){
                    continue;
                }
                if(grid[x2][y2]==1){
                    grid[x2][y2]=0;
                    my_que.push(QNode(x2,y2));
                    area++;
                }
            }
        }
        ans = max(ans,area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]==1)bfs(grid, i,j, ans);
            }
        }
        return ans;
    }
};