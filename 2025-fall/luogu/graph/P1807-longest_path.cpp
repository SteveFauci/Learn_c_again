#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> inDeg(n);
    vector<vector<pair<int,int>>> adj(n); // {v, w}
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;v--;
        inDeg[v]++;
        adj[u].push_back({v,w});
    }
    queue<int> myQue;
    vector<int> dp(n,-2147483647);
    for(int i = 0; i < n; i++){
        if(inDeg[i] == 0){
            myQue.push(i);
            if(i == 0) dp[i] = 0;
        }
    }
    while(!myQue.empty()){
        int x = myQue.front();
        myQue.pop();
        for(auto&[y,w] : adj[x]){
            if(dp[x] != -2147483647){
                dp[y] = max(dp[y], dp[x] + w);
            }
            if(--inDeg[y] == 0){
                myQue.push(y);
            }
        }
    }
    if(dp[n - 1] == -2147483647){
        cout << -1;
    }else{
        cout << dp[n - 1];
    }
}