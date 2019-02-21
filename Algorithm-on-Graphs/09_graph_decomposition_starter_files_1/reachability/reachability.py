#Uses python3

import sys
def BFS_Util(u,adj,visited):
    queue=[]
    queue.append(u)
    visited[u]=True
    while queue:
        u=queue.pop(0)
        for v in adj[u]:
            if visited[v]==False:
                visited[v]=True
                queue.append(v)


def reach(adj, x, y):
    #write your code here
    visited=[False]*(len(adj))
    BFS_Util(x,adj,visited)
    if visited[y]==True:
        return 1
    return 0

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    x, y = data[2 * m:]
    adj = [[] for _ in range(n)]
    x, y = x - 1, y - 1
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)
    print(reach(adj, x, y))
