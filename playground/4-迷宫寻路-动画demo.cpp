// 使用说明：代码最下面有测试用例，粘贴到终端展示寻路过程
// 把第6和45行的 queue 替换成 stack，把52行的my_que.top() 换成 my_que.front()，即实现BFS和DFS的替换

#include <cstdio>
#include <vector>
#include <stack>
#include <unistd.h> // Linux usleep()
#include <cstdlib>  // Linux system()

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct QNode {
    int x, y;
    QNode(int x1, int y1) : x(x1), y(y1) {}
};

// 打印帧
void printMap(const vector<vector<char>>& map, const vector<vector<int>>& booked, int n, int m) {
    system("clear"); // Linux 清屏命令

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (map[i][j] == 'S') {
                printf("\033[1;34mS\033[0m "); // S
            } else if (map[i][j] == 'E') {
                printf("\033[1;31mE\033[0m "); // E
            } else if (booked[i][j]) {
                printf("\033[1;32m+ \033[0m"); // +
            } else if (map[i][j] == '#') {
                printf("\033[1;37m# \033[0m"); // #
            } else {
                printf("\033[1;37m  \033[0m"); // .
            }
        }
        printf("\n");
    }

    usleep(20000); // 控制动画速度（单位：微秒）
}

void bfs(vector<vector<char>>& map, vector<vector<int>>& booked, int startX, int startY) {
    stack<QNode> my_que;
    my_que.push(QNode(startX, startY));
    booked[startX][startY] = 1;

    printMap(map, booked, map.size() - 1, map[0].size() - 1);

    while (!my_que.empty()) {
        QNode temp = my_que.top();
        my_que.pop();
        // 如果当前位置是终点 E，打印并退出 BFS
        if (map[temp.x][temp.y] == 'E') {
            printf("找到终点！\n");
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int x2 = temp.x + dx[i];
            int y2 = temp.y + dy[i];

            if (x2 < 1 || x2 >= map.size() || y2 < 1 || y2 >= map[0].size()) {
                continue;
            }

            if (!booked[x2][y2] && map[x2][y2] != '#') {
                booked[x2][y2] = 1;
                my_que.push(QNode(x2, y2));
                printMap(map, booked, map.size() - 1, map[0].size() - 1); // 走一步画一帧
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<char>> my_map(n + 1, vector<char>(m + 1));
    vector<vector<int>> booked(n + 1, vector<int>(m + 1, 0));

    // 输入地图，并找到起点和终点
    int sx = -1, sy = -1, ex = -1, ey = -1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf(" %c", &my_map[i][j]);

            if (my_map[i][j] == 'S') {
                sx = i, sy = j;
            } else if (my_map[i][j] == 'E') {
                ex = i, ey = j;
            }
        }
    }

    // 如果没有设置起点或终点，给出提示
    if (sx == -1 || sy == -1) {
        printf("未找到起点 S\n");
        return 0;
    }
    if (ex == -1 || ey == -1) {
        printf("未找到终点 E\n");
        return 0;
    }

    // 开始 BFS 寻路
    bfs(my_map, booked, sx, sy);

    // 最后判断是否到达终点
    if (!booked[ex][ey])
        printf("无法到达终点。\n");

    return 0;
}

// 测试用例

/*

6 10
S###.##.##
.#.#.#....
.#.#.####.
.###....#.
..##.####.
#....#E...

15 20
S###################
..................#.
#.#####.########.#..
#.#...#..........#..
#.#####.########.#..
#.................#.
#.#############.###.
#.#.............#...
#.#####.#########...
#.......#...........
#######.##########..
......#.............
.#####.##########.#.
.#...............#..
.################E..

15 20
S...................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
...................E


15 20
####################
#S......#..........#
###.###.#.###..###.#
#...#...#..#.......#
#.#.#####..#.#####.#
#.#........#.#.....#
#.##########.#.###.#
#.#.....#....#.#...#
#.#.###.######.#####
#.#...#........#...#
#.###.#.########.#.#
#.....#.#......#.#E#
#####.#.##.###.#.###
#.....#......#.....#
####################

15 20
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
................S...
....................
...................E
*/