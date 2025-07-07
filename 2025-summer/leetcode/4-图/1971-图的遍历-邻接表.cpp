// 邻接表的遍历。大同小异
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto &&edge :edges){
            int x = edge[0], y = edge[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool> booked(n,0);
        bfs(n,adj,source,booked);
        if(booked[destination])return true;
        return false;
    }
    void bfs(int n, vector<vector<int>>& adj, int source,vector<bool> &booked){
        booked[source] = true;
        queue<int> my_que;
        my_que.push(source);
        while(!my_que.empty()){
            int temp = my_que.front();
            my_que.pop();
            for(int i:adj[temp]){
                if(!booked[i]){
                    booked[i] = true;
                    my_que.push(i);
                }
            }
        }
    }
};