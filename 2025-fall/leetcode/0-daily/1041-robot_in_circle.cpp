#include <string>
using namespace std;
class Solution {
  public:
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    // up rt dn lf
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int dir = 0;
        for (int i = 0; i < 4; i++) {
            for (auto in : instructions) {
                if (in == 'G') {
                    x += dx[dir];
                    y += dy[dir];
                } else if (in == 'L') {
                    dir = (dir + 4 - 1) % 4;
                } else if (in == 'R') {
                    dir = (dir + 4 + 1) % 4;
                }
            }
        }
        return (x && y);
    }
};