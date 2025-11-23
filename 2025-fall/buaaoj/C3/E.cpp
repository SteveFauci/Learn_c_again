#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string text1,text2;
        cin >> text1 >> text2;
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int ans = 1;
        int ans0 = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i - 1] == text2[j - 1]){ dp[i][j] = dp[i-1][j-1] + 1;ans0 = max(ans0, dp[i][j]);}
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                ans = max(ans, dp[i][j]);
            }
        printf("%d %d\n",ans0,ans);
        }
    }
}