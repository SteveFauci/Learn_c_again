#include <stdio.h>
int min = 2147483647;
int map[5005][5005], book[5005][5005];
int x, y, m, n, p, q;
// 注意一下，是第x列第y行。x++是向下，y++是向右。
int  next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(int x, int y, int step) {
    if (x == p && y == q) {
        (step < min) ? (min = step) : (min = min);
        return;
    }
    for (int i = 0; i <= 3; i++) {
        int next_x = x + next[i][0];
        int next_y = y + next[i][1];

        if (next_x < 1 || next_x > n || next_y < 1 || next_y > m) {
            continue;
        }
        if (map[next_x][next_y] == 0 && book[next_x][next_y] == 0) {
            book[next_x][next_y] = 1;
            dfs(next_x, next_y, step + 1);
            book[next_x][next_y] = 0;
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d",&map[i][j]);
        }
    }
    int start_x, start_y;
    scanf("%d%d%d%d",&start_x,&start_y,&p,&q);
    map[start_x][start_y] = 1;
    dfs(start_x,start_y,0);
    printf("%d\n",min);
    return 0;
}
//测试用例：n行m列 网格 起点&终点坐标
/*
5 4
0 0 1 0
0 0 0 0
0 0 1 0
0 1 0 0
0 0 0 1
1 1
4 3
*/
/*
3 5
0 1 1 0 1
0 1 0 0 0
0 0 0 1 0
1 1
3 5
*/