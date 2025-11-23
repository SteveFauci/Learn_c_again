#include<vector>
#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> inDegree(n + 1, 0);
    for(int i = 1; i <= n; i++){
        int temp = 0;
        cin >> temp;
        while(temp != 0){
            adj[i].push_back(temp);
            inDegree[temp] ++;
            cin >> temp;
        }
    }
    queue<int> myQue;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(inDegree[i] == 0) myQue.push(i);
    }
    while(!myQue.empty()){
        int temp = myQue.front();
        ans.push_back(temp);
        myQue.pop();
        for(int next : adj[temp]){
            inDegree[next]--;
            if(inDegree[next] == 0)
                myQue.push(next);
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
}