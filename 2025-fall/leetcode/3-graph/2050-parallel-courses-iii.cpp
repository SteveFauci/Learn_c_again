#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> inDegree(n, 0);
        vector<vector<int>> adj(n);
        for(auto&tmp : relations){
            int pre = tmp[0] - 1;
            int course = tmp[1] - 1;
            adj[pre].push_back(course);
            inDegree[course]++;
        }
        queue<int> myQue;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0) myQue.push(i);
        }
        vector<int> completeTime(n);
        while(!myQue.empty()){
            int x = myQue.front();
            myQue.pop();
            completeTime[x] += time[x];
            for(int y : adj[x]){
                completeTime[y] = max(completeTime[y],completeTime[x]);
                if(--inDegree[y] == 0){
                    myQue.push(y);
                }
            }
        }
        int ans = -1;
        for(int i : completeTime){
            ans = max(ans, i);
        }
        return ans;
    }
};