#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int MOD = 80112002;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> inDeg(n);
    vector<int> ouDeg(n);
    vector<int> dp(n);
    for(int i = 0 ; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        inDeg[v]++;
        ouDeg[u]++;
        adj[u].push_back(v);
    }
    queue<int> myQue;
    for(int i = 0; i < n; i++){
        if(inDeg[i] == 0){
            myQue.push(i);
            dp[i] = 1;
        }
    }
    int ans = 0;
    while(!myQue.empty()){
        int x = myQue.front();
        myQue.pop();
        if(ouDeg[x] == 0){
            ans = (dp[x] + ans) % MOD;
        }
        for(int y : adj[x]){
            dp[y] = (dp[x] + dp[y]) % MOD;
            if(--inDeg[y] == 0){
                myQue.push(y);
            }
        }
    }
    ans %= MOD;
    cout << ans;
}