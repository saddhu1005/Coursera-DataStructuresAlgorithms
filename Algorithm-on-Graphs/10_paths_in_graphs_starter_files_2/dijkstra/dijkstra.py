#Uses python3

import sys
import heapq


def distance(adj, cost, s, t):
    #processed=[False]*(len(adj))
    dist=[-1]*(len(adj))
    heap=[]
    heap.append((0,s))
    dist[s]=0
    parent=[0]*(len(adj))
    parent[s]=s
    while heap:
        key,s=heapq.heappop(heap)
        if key!=dist[s]:
            continue
        for u,w in zip(adj[s],cost[s]):
            if dist[u]==-1:
                dist[u]=dist[s]+w
                heapq.heappush(heap,(dist[u],u))
                parent[u]=s
            elif dist[u]>dist[s]+w:
                dist[u]=dist[s]+w
                parent[u]=s
                heapq.heappush(heap,(dist[u],u))
        #processed[s]=True
    return dist[t]
    #return -1


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
    s, t = data[0] - 1, data[1] - 1
    print(distance(adj, cost, s, t))

