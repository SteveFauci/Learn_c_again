#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> weigh(n + 1, 0);
    vector<int> inDeg(n + 1, 0);
    vector<int> minPath;
    for(int i = 0; i < n; i++){
        int u,v,w;
        cin >> v >> w;
        cin >> u;
        while(u){
            adj[u].push_back(v);
            inDeg[v]++;
            cin >> u;
        }
        weigh[v] = w;
    }
    minPath = weigh;
    queue<int> myQue;
    for(int i = 1; i <= n; i++){
        if(inDeg[i] == 0) myQue.push(i);
    }
    int ans  = 0;
    while(!myQue.empty()){
        int x = myQue.front();
        myQue.pop();
        ans = max(ans, minPath[x]);
        for(int y : adj[x]){
            minPath[y] = max(minPath[x] + weigh[y], minPath[y]);
            if(--inDeg[y] == 0){
                myQue.push(y);
            }
        }
    }
    cout << ans;
}