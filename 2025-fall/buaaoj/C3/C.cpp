#include <climits>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int m;
        cin >> m;
        vector<vector<int>> streamLine(3,vector<int>(m,0));
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < m; j++){
                cin>>streamLine[i][j];
            }
        }
        vector<vector<int>> time(3,vector<int>(3,0));
        for(int i = 0; i < 3; i++){
            for(int j = 0;j < 3; j++){
                cin>>time[i][j];
            }
        }
        vector<vector<long long>> dp(3,vector<long long>(m, 0));
        for(int i = 0; i < 3; i++){
            dp[i][0] = streamLine[i][0];
        }
        for(int i = 1; i < m; i++){                 // 当前工位 i
            for(int j = 0; j < 3; j++){             // 当前第 j 条
                long long minCost = LLONG_MAX;
                for(int k = 0; k < 3; k++){         // 来自第 k 条
                    long long cost = (long long)dp[k][i - 1] + streamLine[j][i] + time[k][j];
                    minCost = min(minCost, cost);
                }
                dp[j][i] = minCost;
            }
        }
        long long ans = min(dp[0][m-1],min(dp[1][m-1],dp[2][m-1]));
        cout<<ans<<endl;
    }
} 