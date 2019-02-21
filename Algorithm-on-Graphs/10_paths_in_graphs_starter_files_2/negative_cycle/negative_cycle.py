#Uses python3

import sys


def negative_cycle(adj, cost):
    s=0 #starting node
    dist=[10000007]*(len(adj))
    parent=[-1]*(len(adj))
    dist[s]=0
    islast=0
    for i in range(len(adj)):
        for u in range(len(adj)):
            for v,w in zip(adj[u],cost[u]):
                if dist[v]>dist[u]+w:
                    dist[v]=dist[u]+w
                    islast=i
                    parent[v]=u
        if islast!=i:
            break
    if islast==len(adj)-1:
        return 1

    return 0


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(zip(data[0:(3 * m):3], data[1:(3 * m):3]), data[2:(3 * m):3]))
    data = data[3 * m:]
    adj = [[] for _ in range(n)]
    cost = [[] for _ in range(n)]
    for ((a, b), w) in edges:
        adj[a - 1].append(b - 1)
        cost[a - 1].append(w)
    print(negative_cycle(adj, cost))
