// clang-format off
// 1. 递归
class Solution1 {
  public:
    int fib(int n) {
        if (n == 1)return 1;
        if (n == 0)return 0;
        return fib(n - 1) + fib(n - 2);
    }
};
// 2. 递归+记忆化储存
class Solution2 {
  public:
    int fib(int n) {
        if (array[n] != 0) return array [n];
        if (n == 1) return 1;
        if (n == 0) return 0;
        array[n] = fib(n - 1) + fib(n - 2);
        return array[n];
    }
  private:
    int array[35] = {0};
};
// clang-format on
// 3. 打表
class Solution3 {
  public:
    int fib(int n) {
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]);
        }
        return dp[n];
    }
  private:
    int dp[105] = {0, 1, 1};
};
// 4. 优化下空间
class Solution4 {
  public:
    int fib(int n) {
        if(n<=1)return n;
        int a = 0,b = 1;
        int c;
        for(int i = 2;i<=n;i++){
            c = a;
            a = b;
            b = c+b;
        }
        return b;
    }
};