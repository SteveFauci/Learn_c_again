#include<vector>
using namespace std;
class Solution {
public:
    const int dx[4] = {0,1,0,-1};
    const int dy[4] = {1,0,-1,0};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<int> res = {};
        int x = 0, y = 0, ori = 0;
        for(int i = 0; i < m * n; i++){
            // visited[x][y] = true;
            res.push_back(matrix[x][y]);
            matrix[x][y] = 114514;
            int x0 = x + dx[ori];
            int y0 = y + dy[ori];
            if(x0 < 0 || x0 >=m || y0 < 0 || y0 >= n || matrix[x0][y0] == 114514)
                ori = (ori + 1) % 4;
            x += dx[ori];
            y += dy[ori];
        }
        return res;
    }
};
