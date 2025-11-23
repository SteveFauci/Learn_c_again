#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        while(!myQue.empty()){
            int temp = myQue.front();
            myQue.pop();
            count++;
            for(int next : adj[temp]){
                inDegree[next]--;
                if(inDegree[next] == 0){
                    myQue.push(next);
                }
            }
        }
        return count == numCourses;
    }
};