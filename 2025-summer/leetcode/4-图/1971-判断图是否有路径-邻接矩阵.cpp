// 用邻接矩阵超出内存限制了，特别是‘稀疏矩阵’造成内存浪费。
// 要探索一下邻接表的遍历。
// 还要学并查集。
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> booked(n,0);
        vector<vector<int>> my_map(n,vector<int>(n,0));
        int sz = edges.size();
        // 构造邻接矩阵
        for(int i = 0; i < sz; i++){
            my_map[edges[i][0]][edges[i][1]] = my_map[edges[i][1]][edges[i][0]] = 1;
        }
        bfs(my_map,source,destination,booked);
        if(booked[destination])
            return true;
        return false;
    }
    void bfs(vector<vector<int>>& my_map,int source,int destination,vector<int> &booked){
        int n = my_map.size();
        booked[source] = 1;
        queue<int> my_que;
        my_que.push(source);
        while(!my_que.empty()){
            int temp = my_que.front();
            my_que.pop();
            for(int i = 0; i < n; i++){
                if(my_map[temp][i] && !booked[i]){
                    my_que.push(i);
                    booked[i] = 1;
                }
            }
        }
    }
};