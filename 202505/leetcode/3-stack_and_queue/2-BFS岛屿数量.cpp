// 没做完
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0 ;j<grid[i].size();j++){
                ans +=search(grid,i,j);
            }
        }
        
        return ans;
    }
    int search(vector<vector<char>>& grid,int  i,int j){
        queue<char>
    }
};