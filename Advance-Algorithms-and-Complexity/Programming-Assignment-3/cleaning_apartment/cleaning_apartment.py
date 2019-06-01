# python3
n, m = map(int, input().split())
edges = [ list(map(int, input().split())) for i in range(m) ]
adj = [[False for _ in range(n)] for _ in range(n)]
for edge in edges:
    adj[edge[0] - 1][edge[1] - 1] = True
    adj[edge[1] - 1][edge[0] - 1] = True
clauses = []
# This solution prints a simple satisfiable formula
# and passes about half of the tests.
# Change this function to solve the problem.
def prereq():
    for i in range(1, n + 1):
        clause = []
        for j in range(n):
            clause.append(i + j * n)
        clauses.append(clause)
        for j in range(n - 1):
            for k in range(j + 1, n):
                clause = []
                clause.append(- i - j * n)
                clause.append(- i - k * n)
                clauses.append(clause)

    for i in range(1, n):
        for j in range(i, n + 1):
            if ( not adj[i - 1][j - 1] and (i != j)):
                for k in range(n - 1):
                    clause = []
                    clause.append(- i - k * n)
                    clause.append( - j - (k + 1) * n )
                    clauses.append(clause)
                    clause = []
                    clause.append(- j - k * n)
                    clause.append(- i - (k + 1) * n)
                    clauses.append(clause)

    for i in range(n):
        clause = []
        for j in range(1, n + 1):
            clause.append(j + i * n)
        clauses.append(clause)
        for j in range(1, n):
            for k in range(j + 1, n + 1):
                clause = []
                clause.append(- j - i * n)
                clause.append(- k - i * n)
                clauses.append(clause)
    pass


def printEquisatisfiableSatFormula():
    prereq()
    print(len(clauses), n * n)
    for clause in clauses:
        clause.append(0)
        print(" ".join(str(v) for v in clause))


printEquisatisfiableSatFormula()
