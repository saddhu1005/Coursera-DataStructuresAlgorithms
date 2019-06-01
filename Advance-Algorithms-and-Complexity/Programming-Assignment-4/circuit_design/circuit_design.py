# python3
# bugged solution 
# not working correctly
n, m = map(int, input().split())
clauses = [ list(map(int, input().split())) for i in range(m) ]
st = [set()]

# This solution tries all possible 2^n variable assignments.
# It is too slow to pass the problem.
# Implement a more efficient algorithm here.
def dfs1(adj, visited, x, order):
    for nxt in adj[x]:
        if not visited[nxt]:
            visited[nxt] = True
            dfs1(adj, visited, nxt, order)
            order.append(nxt)


def dfs2(adj, visited, x, stt):
    stt.add(x)
    for nxt in adj[x]:
        if not visited[nxt]:
            visited[nxt] = True
            dfs2(adj, visited, nxt, stt)
    


def implicationGraph(adj, adj2):
    for clause in clauses:
        x, y, nx, ny = [0] * 4
        if clause[0] > 0:
            x = clause[0] - 1
            nx = x + n
        else:
            x = - clause[0] - 1 + n
            nx = x - n
        if clause[1] > 0:
            y = clause[1] - 1
            ny = y + n
        else:
            y = - clause[1] - 1 + n
            ny = y - n
        
        adj[nx].append(y)
        adj[ny].append(x)
        adj2[x].append(ny)
        adj2[y].append(nx)
    


def settingUp():
    adj = [[] for _ in range(2 * n)]
    adj2 = [[] for _ in range(2 * n)]
    implicationGraph(adj, adj2)

    order = []
    visited = [False for _ in range(2 * n)]

    for i in range(2 * n):
        if not visited[i]:
            visited[i] = True
            dfs1(adj2, visited, i, order)
            order.append(i)
    order.reverse()

    for i in range(len(adj)):
        visited[i] = False
    
    for x in order:
        if not visited[x]:
            stt = set()
            visited[x] = True
            dfs2(adj, visited, x, stt)
            st.append(stt)  


def isSatisfiable():
    settingUp()
    for stt in st:
        for x in stt:
            if stt.__contains__(x + n) or stt.__contains__(x - n):
                return None
    
    result = [ - 1 for _ in range(n)]
    for stt in st:
        for i in stt:
            x, ineg = 0, False
            if i >= n:
                x = i - n
                ineg = True
            else:
                x = i
                ineg = False
            if result[x] == - 1:
                if ineg:
                    result[x] = 1
                else:
                    result[x] = 0
            
    return result


result = isSatisfiable()
if result is None:
    print("UNSATISFIABLE")
else:
    print("SATISFIABLE")
    print(" ".join(str(-i if result[i - 1] == 1 else i) for i in range(1, n + 1)))
