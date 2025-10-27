#include<queue>
using namespace std;

class Solution {
public:
    const int dx[4] = {0,1,0,-1};
    const int dy[4] = {1,0,-1,0};
    struct QNode{
        int x,y;
        QNode(int x1,int y1):x(x1),y(y1){}
    };
    int maxDistance(vector<vector<int>>& grid) {
        queue<QNode> my_que;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0 ;j < n; j++){
                if(grid[i][j]){
                    my_que.push(QNode(i,j));
                    visited[i][j] = 1;
                }
            }
        }
        int dist = 0;
        while(!my_que.empty()){
            bool expanded = false;
            int sz = my_que.size();
            for(int j = 0; j < sz; j++){
                QNode temp = my_que.front();
                for(int i = 0; i < 4; i++){
                    int x = temp.x + dx[i];
                    int y = temp.y + dy[i];
                    if(x < 0 || y < 0 || x >= m || y >= n || visited[x][y]) continue;
                    my_que.push(QNode(x,y));
                    expanded = true;
                    visited[x][y] = 1;
                    my_que.pop();
                    //grid[x][y] = dist;
                }
            }
            if(expanded) dist++;
        }
        return dist;
    }
};