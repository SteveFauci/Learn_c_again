#include<stdio.h>
typedef struct my_stru{
    int x,y,step;
}QNode;
QNode my_que[10005];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int front = 0,rear = -1;

char map[105][105];
int visited[105][105] = {0};

void bfs(char map[][105],int visited[][105],QNode start,QNode end,int m,int n){
    my_que[++rear] = start;
    visited[start.x][start.y] = 1;
    while(rear >= front){
        QNode temp = my_que[front];
        front++;
        for(int i = 0;i < 4; i++){
            int x = temp.x + dx[i];
            int y = temp.y + dy[i];
            if(x<0 || x>=m || y<0 || y>=n || map[x][y]=='#' || visited[x][y] == 1)continue;
            visited[x][y] = 1;
            my_que[++rear] = (QNode){x,y};
        }
    }
}

int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    QNode start,end;
    for(int i = 0;i < m;i++){
        for(int j = 0; j < n;j++){
            scanf(" %c",&map[i][j]);
            if(map[i][j]=='S'){start.x = i;start.y = j;}
            if(map[i][j]=='E'){end.x = i;end.y = j;}
        }
    }
    // start = (QNode){0,0};
    // end = (QNode){m-1,n-1};
    bfs(map,visited,start,end,m,n);
    if(visited[end.x][end.y] == 1)puts("Yes!");
    else puts("No");
}
/*
5 6
S...#.
.##..#
...##.
.#..#.
...#.E

*/