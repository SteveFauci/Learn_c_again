#include<vector>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, 2147483647);
        vector<bool> visited(n + 1, false);
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto tmp : times){
            int u = tmp[0]; int v = tmp[1]; int w = tmp[2];
            adj[u].push_back({v,w});
        }
        dist[k] = 0;
        for(int i = 1; i <= n; i++){
            int u = -1;
            int minDist = 2147483647;
            for(int j = 1; j <= n; j++){
                if(!visited[j] && dist[j] < minDist){
                    minDist = dist[j];
                    u = j;
                }
            }
            if(u == -1)break;
            visited[u] = 1;
            for(auto [v,w] : adj[u]){
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        int ans = -1;
        for(int i = 1; i <= n; i++){
            ans = max(ans, dist[i]);
        }
        return ans == 2147483647? -1 : ans; 
    }
};