#include <stdio.h>
#include <string.h>

#define MAXN 9
#define INF 1000000000LL

long long dp[1 << MAXN]; // dp[mask]: 当前剩余节点为mask时的最小代价
int graph[MAXN][MAXN];   // 邻接矩阵存储边权

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // 初始化邻接矩阵
    memset(graph, 0, sizeof(graph));
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = graph[v][u] = w;
    }

    int full_mask = (1 << n) - 1; // 所有点都在的状态
    for (int i = 0; i < (1 << n); ++i)
        dp[i] = INF;
    dp[full_mask] = 0;

    // 倒序遍历所有mask
    for (int mask = full_mask; mask > 0; --mask) {
        if (dp[mask] == INF)
            continue;

        // 枚举当前mask中所有存在的点
        for (int u = 1; u <= n; ++u) {
            if (((mask >> (u - 1)) & 1) == 0)
                continue;

            // 计算删除u时涉及的边数和权值和
            int cnt = 0;
            long long cost = 0;
            for (int v = 1; v <= n; ++v) {
                if (v != u && ((mask >> (v - 1)) & 1) && graph[u][v] > 0) {
                    cnt++;
                    cost += graph[u][v];
                }
            }

            int next_mask = mask ^ (1 << (u - 1)); // 删除u后的新mask
            if (dp[next_mask] > dp[mask] + cnt * cost)
                dp[next_mask] = dp[mask] + cnt * cost;
        }
    }

    printf("%lld\n", dp[0]); // 最终所有点都被删除的状态
    return 0;
}