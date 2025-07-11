#include <queue>
#include <vector>
using namespace std;
class Solution {
  public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<vector<int>> my_que;
        int n = rooms.size();
        vector<bool> visited(n,false);

        my_que.push(rooms[0]);
        visited[0] = true;

        while(!my_que.empty()){
            vector<int> temp = my_que.front();
            my_que.pop();
            for(int i = 0; i < temp.size(); i++){
                if(!visited[temp[i]]){
                    visited[temp[i]] = true;
                    my_que.push(rooms[temp[i]]);
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(!visited[i])return false;
        }
        return true;
    }
};