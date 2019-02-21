#Uses python3

import sys
import queue


def BellMan_Ford(adj,cost,distance,s,reachable):
    distance[s]=0
    reachable[s]=1
    for i in range(len(adj)-1):
        for u in range(len(adj)):
            for v,w in zip(adj[u],cost[u]):
                if distance[v]>distance[u]+w and distance[u]!=10**19:
                    distance[v]=distance[u]+w
                    reachable[v]=1

    pass


def shortet_paths(adj, cost, s, distance, reachable, shortest):
    BellMan_Ford(adj,cost,distance,s,reachable)
    ncycle=[]
    for u in range(len(adj)):
            for v,w in zip(adj[u],cost[u]):
                if distance[v]>distance[u]+w and distance[u]!=10**19:
                    distance[v]=distance[u]+w
                    ncycle.append(v)
    if ncycle:
        queue=[]
        visited=[False]*(len(adj))
        while ncycle:
            s=ncycle.pop(0)
            if visited[s]==True:
                continue
            queue.append(s)
            visited[s]=True
            shortest[s]=0
            while queue:
                t=queue.pop(0)
                for u in adj[t]:
                    if visited[u]==False:
                        visited[u]=True
                        shortest[u]=0
                        queue.append(u)
    pass

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
    s = data[0]
    s -= 1
    distance = [10**19] * n
    reachable = [0] * n
    shortest = [1] * n
    shortet_paths(adj, cost, s, distance, reachable, shortest)
    for x in range(n):
        if reachable[x] == 0:
            print('*')
        elif shortest[x] == 0:
            print('-')
        else:
            print(distance[x])

