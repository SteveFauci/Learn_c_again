#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t,m;
    cin >> t >> m;
    vector<int> time(m), value(m);
    for(int i = 0; i < m; i++){
        cin >> time[i] >> value[i];
    }
    vector<int> dp(t + 1, 0);
    for(int i = 0; i < m; i++){
        for(int j = t; j >= time[i]; j--){
            dp[j] = max(dp[j], dp[j - time[i]] + value[i]);
        }
    }
    cout << dp[t];
}