#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    struct QNode{
        int x,y;
        QNode(int x1,int y1):x(x1),y(y1){};
    };
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<QNode> my_que;
        int m = mat.size(),n = mat[0].size();
        vector<vector<int>> seen(m,vector<int>(n));
        vector<vector<int>> dist(m,vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!mat[i][j]){
                    my_que.push(QNode(i,j));
                    seen[i][j] = 1;
                }
            }
        }
        while(!my_que.empty()){
            QNode temp = my_que.front();
            my_que.pop();
            for(int i = 0; i < 4; i++){
                int x = temp.x + dx[i];
                int y = temp.y + dy[i];
                if(x >= 0 && x <m && y >= 0 && y<n && !seen[x][y]){
                    dist[x][y] = dist[temp.x][temp.y] + 1;
                    my_que.push(QNode(x,y));
                    seen[x][y] = 1;
                }
            }
        }
        return dist;
    }
};