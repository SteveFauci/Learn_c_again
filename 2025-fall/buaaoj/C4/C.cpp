#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, volume;
    cin >> n >> volume;
    vector<long long> vol(n), value(n);
    for(int i = 0; i < n; i++){
        cin >> vol[i] >> value[i];
    }
    vector<long long> dp(volume + 1, 0);
    for(int i = 0; i < n; i++){
        for(int j = volume; j >= vol[i]; j--){
            dp[j] = max(dp[j], dp[j - vol[i]] + value[i]);
        }
    }
    cout << dp[volume];
}