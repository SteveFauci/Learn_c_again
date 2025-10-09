#include<vector>
using namespace std;
class Solution {
public:
    const int dx[4] = {0,1,0,-1};
    const int dy[4] = {1,0,-1,0};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> my_mat(n,vector<int>(n));
        int i = 0, j = 0, dir = 0;
        for(int val = 1; val <= n * n; val++){
            my_mat[i][j] = val;
            int x = i + dx[dir];
            int y = j + dy[dir];
            if(x < 0 || x >= n || y < 0 || y >= n || my_mat[x][y]){
                dir = (dir + 1) % 4;
            }
            i += dx[dir];
            j += dy[dir];
        }
        return my_mat;
    }
};