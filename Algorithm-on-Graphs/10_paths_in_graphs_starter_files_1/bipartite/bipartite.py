#Uses python3

import sys
import queue
def getpirate(p):
    if p==0:
        return 1
    return 0

def bfs(adj,pirate,visited,s):
    queue=[]
    processed=[False]*(len(adj))
    queue.append(s)
    visited[s]=True
    pirate[s]=0
    while queue:
        s=queue.pop(0)
        processed[s]=True
        for v in adj[s]:
            if visited[v]==False:
                visited[v]=True
                pirate[v]=getpirate(pirate[s])
                queue.append(v)
            elif processed[v]==False and pirate[v]==pirate[s]:
                return False
    return True
def bipartite(adj,n):
    visited=[False]*(len(adj))
    pirate=[0]*n
    bool=False
    bool=bfs(adj,pirate,visited,0)
    if bool==False:
        return 0
    return 1

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)
    print(bipartite(adj,n))
