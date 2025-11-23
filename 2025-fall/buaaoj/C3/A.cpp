#include<cstdio>
#include<vector>
#include<climits>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    if (n <= 1) {
        printf("0\n");
        return 0;
    }

    vector<int> arr(n+2);
    for(int i = 0; i <= n; i++){
        scanf("%d",&arr[i]);
    }
    vector<vector<long long>> dp(n+3,vector<long long>(n+3,0));
    for(int y = 2; y <= n; y++){
        for(int i = 1; i <= n - y + 1; i++){
            int j = i + y - 1;
            dp[i][j] = LLONG_MAX;
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + (long long)arr[i-1] * arr[k] * arr[j]);
            }
        }
    }
    printf("%lld\n",dp[1][n]);
}