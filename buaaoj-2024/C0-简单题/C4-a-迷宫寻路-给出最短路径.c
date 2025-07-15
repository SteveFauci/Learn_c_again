#include <stdio.h>
#define LEN 105 // 迷宫大小
#define DIR 4   // 四个方向
typedef struct _Point {
    int x, y; // 当前位置的行号、列号
    int len;  // 抵达当前位置的最短路径长度
} Point;


int step[DIR][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; 
int   maze[LEN][LEN];                  // 记录迷宫每个位置能否被抵达
Point queue[LEN * LEN];                // 记录路径中的点的队列
int   head, tail;

int   find_path(Point start,Point end) // 寻找并返回从起点到终点的最短路径，若找不到则返回-1
{
    queue[tail++] = start; // 将起点入队
    while (head < tail)    // 队列不为空
    {
        Point current = queue[head++]; // 将当前遍历的点出队
        for (int i = 0; i < DIR; ++i) {
            Point next = {current.x + step[i][0], current.y + step[i][1],
                          current.len + 1}; // 计算新位置及其最短路径长度
            if (maze[next.x][next.y]) // 该点能被抵达，则将其入队
                queue[tail++] = next;
            maze[next.x][next.y] = 0; // 已抵达过该点，标记为不可抵达
            if (next.x == end.x && next.y == end.y) // 若该点与终点位置相同，则找到了最短路径
                return next.len;
        }
    }
    return -1; // 队列为空时仍未找到，则返回-1
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    Point start, end;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char c;
            scanf(" %c", &c); // 跳过可能的空白符，读取每个点
            if (c == '.')     // 可以被抵达
                maze[i][j] = 1;
            if (c == 'S') // 记录起点
            {
                start.x = i;
                start.y = j;
                start.len = 1;
            }
            if (c == 'E') // 记录终点
            {
                end.x = i;
                end.y = j;
                // 终点的len不重要，用不到
            }
        }
    printf("%d", find_path(start, end));
    return 0;
}