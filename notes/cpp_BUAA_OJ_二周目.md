# 0

用 % 代表取模（又称取余）运算，即 a%b=amodb 代表 a 除以 b 留下的余数。

取模运算的加法性质：(a%p+b%p)%p=(a+b)%p

取模运算的乘法性质：(a×b)%p=((a%p)×(b%p))%p

> 待办：模逆元（？）

例：输入 n，输出 1000n^2(50n+7)mod998244353

```c
long long p = 998244353;
long long n;
scanf("%lld",&n);
// 运算中间也可能爆 long long，所以中间每一步都要取模。
long long ans = (((1000 * n % p) * n % p) * ((50 * n % p + 7) % p)) % p;
printf("%lld",ans);
```

连乘举例 (避免括号嵌套)：

```c
long long MOD = 998244353;
long long n;
long long ans = 0;
...
n %= MOD;
ans = n % MOD;
ans = (ans % MOD) * (n % MOD) % MOD;
ans = (ans % MOD) * ((n + 1) % MOD) % MOD;
ans = (ans % MOD) * ((2 * n + 1) % MOD) % MOD;
...
```
