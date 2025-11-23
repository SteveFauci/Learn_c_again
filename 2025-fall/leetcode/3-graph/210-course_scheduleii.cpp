#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto&tmp : prerequisites){
            int course = tmp[0];
            int pre = tmp[1];
            inDegree[course]++;
            adj[pre].push_back(course);
        }
        queue<int> myQue;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0) myQue.push(i);
        }
        int count = 0;
        vector<int> ans;
        while(!myQue.empty()){
            int temp = myQue.front();
            ans.push_back(temp);
            myQue.pop();
            count++;
            for(int next : adj[temp]){
                inDegree[next]--;
                if(inDegree[next] == 0){
                    myQue.push(next);
                }
            }
        }
        return ans;
    }
};