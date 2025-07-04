// 很像二叉树层序遍历，用队列储存节点。
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    struct QNode{
        int x,y;//cpp的初始化列表 & 构造函数
        QNode(int x1,int y1):x(x1),y(y1){};
    };
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size();i++){
            for(int j = 0; j < grid[0].size();j++){
                if(grid[i][j]=='1'){
                    ans++;
                    bfs(grid,i,j);
                }
            }
        }
        return ans;
    }
    void bfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        queue<QNode> my_que;
        my_que.push(QNode(x,y));
        while(!my_que.empty()){
            QNode temp = my_que.front();
            my_que.pop();
            for(int i = 0; i < 4; i++){
                int x = temp.x + dx[i];
                int y = temp.y + dy[i];
                if(x < 0 || y < 0 || x >= grid.size() || y>= grid[0].size()){
                    continue;
                }
                if(grid[x][y]=='0'){
                    continue;
                }
                grid[x][y] = '0';
                my_que.push(QNode(x,y));
            }
        }
    }
};