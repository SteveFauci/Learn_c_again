//把queue全换成stack就是dfs了，不重写了
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> visited;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        visited.resize(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(visited[i]==0){
                ans++;
                bfs(isConnected,n,i);
            }
        }
        return ans;
    }
    void bfs(vector<vector<int>>& M,int n,int x){
        visited[x]=1;
        queue<int> my_que;
        my_que.push(x);
        while(!my_que.empty()){
            int temp = my_que.front();
            my_que.pop();
            for(int i = 0; i < n; i++){
                if(visited[i] == 0 && M[temp][i] == 1 && temp!=i){
                    visited[i]=1;
                    my_que.push(i);
                }
            }
        }
    }
};