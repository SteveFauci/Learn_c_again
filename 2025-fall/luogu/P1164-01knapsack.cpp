#include <iostream>
#include <vector>
using namespace std;
int main() {
    int num, val;
    cin >> num >> val;
    vector<int> value(num);
    for (int i = 0; i < num; i++) {
        cin >> value[i];
    }
    vector<vector<int>> dp(num + 1, vector<int>(val + 1, 0)); // 前 i 菜，恰好花 j 的方案数
    dp[0][0] = 1;
    for (int i = 1; i <= num; i++) {
        for (int j = 0; j <= val; j++) {
            dp[i][j] = dp[i - 1][j]; // 先不买，j 是花的钱
            if (j >= value[i - 1]){
                dp[i][j] += dp[i-1][j - value[i-1]];
            }
        }
    }
    cout << dp[num][val];
}