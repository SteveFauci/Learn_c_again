//BUAA OJ 的地图比较小，10*10的DFS没超时
//洛谷的100*100超时了。。。
#include <stdio.h>
int ans = 0;
char map[15][15];
int book[15][15];
int x, y;
// 注意一下，是第x列第y行。x++是向下，y++是向右。
int  next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(int x, int y, int step) {
    if (x == 10 && y == 10) {
        ans = 1;
        return;
    }
    for (int i = 0; i <= 1; i++) {
        int next_x = x + next[i][0];
        int next_y = y + next[i][1];

        if (next_x < 1 || next_x > 10 || next_y < 1 || next_y > 10) {
            continue;
        }
        if (map[next_x][next_y] == '1' && book[next_x][next_y] == 0) {
            book[next_x][next_y] = 1;
            dfs(next_x, next_y, step + 1);
            if(ans)return;
            book[next_x][next_y] = 0;
        }
    }
}

int main(){
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            scanf(" %c",&map[i][j]);
        }
    }
    map[1][1] = 1;
    dfs(1,1,0);
    ans == 1?puts("YES"):puts("NO");
    return 0;
}
/*
1 1 1 1 1 1 0 1 1 0
0 0 1 0 0 0 0 0 0 0
0 0 1 1 0 0 0 0 0 0
0 0 0 1 1 1 1 1 0 0
0 0 0 1 0 0 0 1 0 0
0 0 0 1 0 0 0 1 0 0
0 0 0 1 0 0 0 1 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1 1 1
*/
/*
1 1 1 1 1 1 0 1 1 0
0 1 1 0 0 0 0 0 0 0
0 1 0 1 0 0 0 0 0 0
0 1 0 1 1 1 1 1 0 0
0 1 0 1 0 1 0 1 0 0
0 1 0 1 0 1 0 1 0 0
0 1 0 1 0 1 0 1 0 0
0 1 0 0 0 1 0 1 0 0
0 1 1 1 1 1 0 1 0 0
0 0 0 0 0 0 0 1 1 1
*/