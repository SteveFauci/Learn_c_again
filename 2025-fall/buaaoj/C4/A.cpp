#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool>        visited(n + 1, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int        cnt = 0;
    queue<int> myQue;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            myQue.push(i);
            cnt++;
            visited[i] = true;
        }
        while (!myQue.empty()) {
            int temp = myQue.front();
            myQue.pop();
            for (auto next : adj[temp]) {
                if (!visited[next]) {
                    myQue.push(next);
                    visited[next] = true;
                }
            }
        }
    }
    cout << cnt;
}