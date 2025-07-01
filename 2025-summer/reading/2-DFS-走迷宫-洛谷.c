//超时了，要改用BFS
#include <stdio.h>
int ans = 0;
char map[105][105];
int book[105][105];
int x, y, m, n;
// 注意一下，是第x列第y行。x++是向下，y++是向右。
int  next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(int x, int y, int step) {
    if (x == n && y == m) {
        ans = 1;
        return;
    }
    for (int i = 0; i <= 3; i++) {
        int next_x = x + next[i][0];
        int next_y = y + next[i][1];

        if (next_x < 1 || next_x > n || next_y < 1 || next_y > m) {
            continue;
        }
        if (map[next_x][next_y] == '.' && book[next_x][next_y] == 0) {
            book[next_x][next_y] = 1;
            dfs(next_x, next_y, step + 1);
            if(ans)return; // 这里剪枝提前返回，不剪枝10分，剪枝40分。满分100。剩下的测试点全部tle
            book[next_x][next_y] = 0;
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf(" %c",&map[i][j]);
        }
    }
    map[1][1] = 1;
    dfs(1,1,0);
    ans == 1?puts("Yes"):puts("No");
    return 0;
}
/*
6 10
.###.##.##
.#........
.#.#.####.
.###....#.
..##.####.
#....#....
*/