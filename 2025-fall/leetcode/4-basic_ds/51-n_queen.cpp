#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<string>>&ans, vector<bool> &visited, vector<int> &queen, vector<bool> &d1, vector<bool> &d2, int &row){
        int n = visited.size();
        if(row == visited.size()){
            vector<string> board(n, string(n,'.'));
            for(int r = 0; r < n; r++){
                board[r][queen[r]] = 'Q';
            }
            ans.push_back(board);
            return;
        }
        for(int i = 0; i < n; i++){
            int t1 = row - i + n - 1;
            int t2 = row + i;
            if(visited[i])continue;
            if(d1[t1] || d2[t2])continue;
            queen[row] = i;
            d1[t1] = d2[t2] = visited[i] = true;
            row++;

            dfs(ans,visited,queen,d1,d2,row);

            d1[t1] = d2[t2] = visited[i] = false;
            row--;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> visited(n,0);
        vector<bool> d1(2 * n - 1, 0);
        vector<bool> d2(2 * n - 1, 0);
        vector<vector<string>> ans = {};
        vector<int> queen(n,0);
        vector<string> cur = {};
        int row = 0;
        dfs(ans,visited,queen,d1,d2,row);
        return ans;
    }
};