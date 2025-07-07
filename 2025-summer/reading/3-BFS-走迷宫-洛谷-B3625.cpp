#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

struct QNode{
    int x,y;
    QNode(int x1,int y1):x(x1),y(y1){};
};

void bfs(vector<vector<char>> &map,vector<vector<int>> &booked,int x,int y){
    queue<QNode> my_que;
    my_que.push(QNode(x,y));
    booked[x][y] = 1;
    while(!my_que.empty()){
        QNode temp = my_que.front();
        my_que.pop();
        for(int i = 0; i < 4; i++){
            int x2 = temp.x + dx[i];
            int y2 = temp.y + dy[i];
            if(x2 < 1 || x2 >= map.size() || y2 < 1 || y2 >= map[0].size()){
                continue;
            }
            if(booked[x2][y2]!=1 && map[x2][y2] == '.'){
                booked[x2][y2]=1;
                my_que.push(QNode(x2,y2));
            }
        }
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<char>> my_map(n+1,vector<char>(m+1));
    vector<vector<int>> booked(n+1,vector<int>(m+1,0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf(" %c",&my_map[i][j]);
        }
    }
    bfs(my_map,booked,1,1);
    if(booked[n][m])puts("Yes");
    else puts("No");
}
