#include<vector>
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
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int step = 0;
        queue<QNode> my_que;
        int fresh = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) my_que.emplace(QNode(i,j));
                if(grid[i][j] == 1) fresh++;
            }
        }
        if(fresh == 0) return 0;

        while(!my_que.empty() && fresh>0){
            int cur_sz = my_que.size();
            for(int j = 0; j < cur_sz; j++){
                QNode temp = my_que.front();
                my_que.pop();
                for(int i = 0; i < 4; i++){
                    int x = temp.x + dx[i];
                    int y = temp.y + dy[i];
                    if(x < 0 || x >= m || y < 0 || y >= n) continue;
                    if(grid[x][y] == 1) {
                        grid[x][y] = 2;
                        fresh--;
                        my_que.emplace(QNode(x,y));
                    }
                }
            }
            step++;
        }

        return fresh==0?step:-1;
    }
};