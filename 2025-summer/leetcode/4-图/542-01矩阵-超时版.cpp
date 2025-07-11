// 复杂度太高了，待优化。。
#include <queue>
#include <vector>
using namespace std;
class Solution {
  public:
    int  dx[4] = {0, 1, 0, -1};
    int  dy[4] = {1, 0, -1, 0};
    struct QNode{
        int x,y;
        QNode(int x1,int y1):x(x1),y(y1){};
    };
    void bfs(vector<vector<int>>& mat, int x0, int y0) {
        int dist = 1;
        queue<QNode> my_que;
        my_que.push(QNode(x0,y0));
        while(!my_que.empty()){
            int sz = my_que.size();
            for(int k = 0; k < sz; k++){
                QNode temp = my_que.front();
                for(int i = 0; i < 4; i++){
                    int x = temp.x + dx[i];
                    int y = temp.y + dy[i];
                    if(x < 0 || x >= mat.size() || y < 0 || y >= mat[0].size()){
                        continue;
                    }
                    if(mat[x][y] == 0) {
                        mat[x0][y0] = dist;
                        return;
                    }
                    my_que.push(QNode(x,y));
                }
                my_que.pop();
            }
            dist++;
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] != 0) bfs(mat,i,j);
            }
        }
        return mat;
    }
};