#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    struct QNode{
        int x,y;
        QNode(int x1,int y1):x(x1),y(y1){}
    };
    void solve(vector<vector<char>>& board) {
        int m = board.size(),n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<QNode> my_que;
        // 从最外圈向内渗透，O为可走路径，X为墙壁。无法渗入的最后全变为X
        for(int i = 0; i < m; i++){
            if(board[i][0]=='O') my_que.emplace(QNode(i,0));
            if(board[i][n-1]=='O') my_que.emplace(QNode(i,n-1));
        }
        for(int i = 0; i < n; i++){
            if(board[0][i]=='O') my_que.emplace(QNode(0,i));
            if(board[m-1][i]=='O') my_que.emplace(QNode(m-1,i));
        }

        while(!my_que.empty()){
            QNode temp = my_que.front();
            my_que.pop();
            visited[temp.x][temp.y] = true;
            for(int i = 0; i < 4; i++){
                int x = temp.x + dx[i];
                int y = temp.y + dy[i];
                if(x < 0 || x >= m || y < 0 || y >= n) continue;
                if(visited[x][y] || board[x][y] == 'X') continue;
                my_que.emplace(QNode(x,y));
                visited[x][y] = true;
            }
        }

        for(int i = 0;i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j])board[i][j]='X';
            }
        }
    }

};

/*
[
    ["X","X","X","X"],
    ["X","O","O","X"],
    ["X","X","O","X"],
    ["X","O","X","X"]
]
*/