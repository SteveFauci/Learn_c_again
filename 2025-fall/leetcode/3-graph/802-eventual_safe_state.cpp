#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> inDeg(n);
        vector<vector<int>> revGraph(n);
        for(int i = 0; i < n; i++){
            for(int j : graph[i]){
                revGraph[j].push_back(i);
                inDeg[i]++;
            }
        }
        vector<int> ans;
        queue<int> myQue;
        for(int i = 0; i < n; i++){
            if(inDeg[i] == 0){
                myQue.push(i);
                ans.push_back(i);
            }
        }
        while(!myQue.empty()){
            int temp = myQue.front();
            myQue.pop();
            for(int j : revGraph[temp]){
                if(--inDeg[j] == 0){
                    ans.push_back(j);
                    myQue.push(j);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};