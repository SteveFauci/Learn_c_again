#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n + 1);
    vector<int> inDegree(n + 1, 0);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        inDegree[v]++;
    }
    queue<int> myQue;
    for(int i = 1;i <= n; i++){
        if(inDegree[i]==0) myQue.push(i);
    }
    while(!myQue.empty()){
        int temp = myQue.front();
        cout << temp << ' ';
        myQue.pop();
        for(auto temp2 : adj[temp]){
            int next = temp2.first;
            inDegree[next]--;
            if(inDegree[next] == 0)
                myQue.push(next);
        }
    }
    cout << endl;

    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> myQue2;
    dist[1] = 0;
    myQue2.push({0,1});
    while(!myQue2.empty()){
        auto [ d, u] = myQue2.top();
        myQue2.pop();
        if(d > dist[u]) continue;
        for(auto[v, w] : adj[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                myQue2.push({dist[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(dist[i] == 2147483647) {cout << -1 << " "; continue;}
        cout << dist[i] << ' ';
    }
    return 0;
    

}