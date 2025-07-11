#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int>my_que;
        vector<int> visited(n,0);

        visited[0] = 1;
        for(int i = 0; i < rooms[0].size(); i++){
            my_que.push(rooms[0][i]);   
        }
        while(!my_que.empty()){
            int temp = my_que.front();
            visited[temp] = 1;
            my_que.pop();
            for(int i = 0; i < rooms[temp].size(); i++){
                if(!visited[rooms[temp][i]]) my_que.push(rooms[temp][i]);
            }
        }
        for(int i = 0; i < n; i++){
            if(!visited[i])return false;
        }
        return true;
    }
};