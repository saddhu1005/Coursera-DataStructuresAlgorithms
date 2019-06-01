# python3
n, m = map(int, input().split())
edges = [ list(map(int, input().split())) for i in range(m) ]

# This solution prints a simple satisfiable formula
# and passes about half of the tests.
# Change this function to solve the problem.

def printEquisatisfiableSatFormula():
    print((n + m * 3), n * 3)
    for i in range(1, n + 1):
        print(i, i + n, i + n * 2, 0)
    for edge in edges:
        print(- edge[0], - edge[1], 0)
        print( -edge[0] - n, - edge[1] -n, 0) 
        print(-edge[0] - n * 2, - edge[1] - n * 2, 0)


printEquisatisfiableSatFormula()
