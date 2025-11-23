import sys
from collections import deque

line1 = sys.stdin.readline().split()
n, m, s, t = map(int, line1)

# 转为 0-based 索引方便处理
s -= 1
t -= 1

graph = [[] for _ in range(n)]      # 正向图
revGraph = [[] for _ in range(n)]   # 反向图
inDeg = [0] * n                     # 入度
outDeg = [0] * n                    # 出度

for _ in range(m):
    u, v, w = map(int, sys.stdin.readline().split())
    u -= 1
    v -= 1
    graph[u].append((v, w))
    revGraph[v].append((u, w))
    inDeg[v] += 1
    outDeg[u] += 1

# 1. 正向拓扑排序 计算最早开始时间 TE
def calculateTE():
    TE = [-1] * n
    # 只有起点 s 的时间设为 0
    TE[s] = 0
    # 拷贝入度数组用于拓扑排序
    currInDeg = list(inDeg)
    queue = deque()
    for i in range(n):
        if currInDeg[i] == 0:
            queue.append(i)
    while queue:
        u = queue.popleft()
        for v, w in graph[u]:
            if TE[u] != -1:
                if TE[v] < TE[u] + w:
                    TE[v] = TE[u] + w
            currInDeg[v] -= 1
            if currInDeg[v] == 0:
                queue.append(v)
    return TE

TE = calculateTE()

# 2. 反向拓扑排序 计算最晚开始时间 TL
def calculateTL(TE):
    TL = [float('inf')] * n
    currOutDeg = list(outDeg)
    queue = deque()
    for i in range(n):
        if currOutDeg[i] == 0:
            if TE[i] != -1:
                TL[i] = TE[i]
            queue.append(i)
    while queue:
        v = queue.popleft()
        for u, w in revGraph[v]:
            if TL[v] != float('inf'):
                if TL[u] > TL[v] - w:
                    TL[u] = TL[v] - w
            currOutDeg[u] -= 1
            if currOutDeg[u] == 0:
                queue.append(u)
    return TL

TL = calculateTL(TE)

# 关键路径长度
print(TE[t])

# 输出每个点的 TE, TL, Slack
for i in range(n):
    te = TE[i]
    tl = TL[i]
    diff = tl - te
    print(f"{te} {tl} {diff}")

# 3. 寻找所有关键路径
paths = []

def dfs(u, currPath, currLen):
    if u == t:
        if currLen == TE[t]:
            path = [x + 1 for x in currPath]
            paths.append(path)
        return
    for v, w in graph[u]:
        if TE[v] == TE[u] + w:
            currPath.append(v)
            dfs(v, currPath, currLen + w)
            currPath.pop()

dfs(s, [s], 0)

paths.sort(key=lambda x: (len(x), x))

for path in paths:
    print(*(path))