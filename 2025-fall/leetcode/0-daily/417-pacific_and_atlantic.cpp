#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    const int dx[4] = {0,1,0,-1};
    const int dy[4] = {1,0,-1,0};
    struct QNode{
        int x,y,val;
        QNode(int x1,int y1, int v1):x(x1),y(y1),val(v1){}
    };
    void my_bfs(queue<QNode> &que,vector<vector<int>> &vis, vector<vector<int>> & heights){
        int m = heights.size(), n = heights[0].size();
        while(!que.empty()){
            auto temp = que.front();
            que.pop();
            
            for(int i = 0; i < 4; i++){
                int x = temp.x + dx[i];
                int y = temp.y + dy[i];
                if(x < 0 || x >= m || y < 0 || y >= n) continue;
                
                if(!vis[x][y] && heights[x][y] >= temp.val) {
                    vis[x][y] = 1;
                    que.push(QNode(x,y,heights[x][y]));
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> visitedP(m,vector<int>(n,0));
        vector<vector<int>> visitedA(m,vector<int>(n,0));
        queue<QNode> my_queP,my_queA;
        for(int i = 0; i < n; i++){
            visitedP[0][i] = 1;
            my_queP.push(QNode(0,i,heights[0][i]));
            visitedA[m-1][i] = 1;
            my_queA.push(QNode(m-1,i,heights[m-1][i]));
        }
        for(int i = 0; i < m; i++){
            visitedP[i][0] = 1;
            my_queP.push(QNode(i,0,heights[i][0]));
            visitedA[i][n-1] = 1;
            my_queA.push(QNode(i,n-1,heights[i][n-1]));
        }
        my_bfs(my_queA, visitedA, heights);
        my_bfs(my_queP, visitedP, heights);
        vector<vector<int>> ans;
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n; j++){
                if(visitedA[i][j] && visitedP[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};