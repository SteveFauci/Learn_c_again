#include <climits>
#include <functional>
#include<queue>
#include <utility>
#include<vector>
#include<iostream>
using namespace std;
int main(){
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int,int>>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    vector<bool> visited(n + 1);
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> myQue;
    dist[s] = 0;
    myQue.push({0,s});
    while(!myQue.empty()){
        auto [ d, u] = myQue.top();
        myQue.pop();
        if(d > dist[u]) continue;
        for(auto[v, w] : adj[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                myQue.push({dist[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << dist[i] << ' ';
    }
    return 0;

}