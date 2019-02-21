#Uses python3

import sys
def dfs_util(v,visited,adj,source):
    global cycle
    visited[v]=True
    for u in adj[v]:
        if visited[u]==False:
            dfs_util(u,visited,adj,source)
        elif u==source:
            cycle=True
def acyclic(adj):
    global cycle
    for v in range(len(adj)):
        cycle=False
        visited=[False]*(len(adj))
        dfs_util(v,visited,adj,v)
        if cycle:
            return 1

    return 0
cycle=False
if __name__ == '__main__':
    input = sys.stdin.read()

    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
    print(acyclic(adj))
