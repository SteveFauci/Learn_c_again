#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s;
    cin >> n >> m >> s;  // n个点，m条边，源点s
    
    // 构建邻接表
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;  // 读入：起点u，终点v，边权w
        adj[u].push_back({v, w});
    }
    
    // 现在可以使用Dijkstra算法
    vector<int> dist(n + 1, INT_MAX);
    vector<bool> vis(n + 1, false);
    dist[s] = 0;
    
    for (int i = 1; i <= n; i++) {
        int u = -1, min_dist = INT_MAX;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }
        
        if (u == -1) break;
        vis[u] = true;
        
        // 遍历u的所有邻居
        for (auto [v, w] : adj[u]) {  // v是邻居，w是边权
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    
    return 0;
}