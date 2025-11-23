import heapq

n, m, s, t = map(int, input().split())
INF = 2147483647
graph = [[INF] * (n + 1) for _ in range(n + 1)]
for _ in range(m):
    u, v, w = map(int, input().split())
    if u == v:
        continue
    if w < graph[u][v]:  # 取最小边权
        graph[u][v] = w
        graph[v][u] = w

adj = [[] for _ in range(n + 1)]
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if graph[i][j] != INF and i != j:
            adj[i].append((j, graph[i][j]))

dist = [INF] * (n + 1)
prev = [-1] * (n + 1)
dist[s] = 0
heap = [(0, s)]

while(heap):
    d, u = heapq.heappop(heap)
    if d > dist[u]:
        continue
    for v, w in adj[u]:
        new_dist = dist[u] + w
        if new_dist < dist[v]:
            dist[v] = new_dist
            prev[v] = u  # 记录前驱
            heapq.heappush(heap, (new_dist, v))
print(dist[t])

path = []
cur = t
while cur != -1:
    path.append(cur)
    cur = prev[cur]
path.reverse()
print(' '.join(map(str, path)))