#Uses python3

import sys
import operator
sys.setrecursionlimit(200000)
def dfs_util(v,rev,visited,pre,post):
    global i
    visited[v]=True
    pre.append((v,i))
    i+=1
    for u in rev[v]:
        if visited[u]==False:
            dfs_util(u,rev,visited,pre,post)
    post.append((v,i))
    i+=1

def dfs(v,adj,visited):
    visited[v]=True
    for u in adj[v]:
        if visited[u]==False:
            dfs(u,adj,visited)

def number_of_strongly_connected_components(adj,rev):
    result = 0
    preorder=[]
    postorder=[]
    visited=[False]*(len(adj))
    for u in range(len(rev)):
        if visited[u]==False:
            dfs_util(u,rev,visited,preorder,postorder)
    postorder.sort(key=lambda x:x[1])
    postorder.reverse()
    visited=[False for _ in range(len(adj))]
    for (a,b) in postorder:
        if visited[a]==False:
            dfs(a,adj,visited)
            result+=1
    return result
i=1
if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    rev = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
        rev[b - 1].append(a - 1)
    print(number_of_strongly_connected_components(adj,rev))
