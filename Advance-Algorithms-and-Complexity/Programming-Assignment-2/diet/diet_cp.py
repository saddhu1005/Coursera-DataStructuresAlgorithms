# python3
from sys import stdin
import copy


VeryBigInteger = 1e9


class Equation:
    def __init__(self, a, b):
        self.a = a
        self.b = b


class Position:
    def __init__(self, column, row):
        self.column = column
        self.row = row


def Prime_element(a, used_rows, used_columns):
    m = len(a)
    pivot_element = Position(0, 0)
    while used_rows[pivot_element.row]:
        pivot_element.row += 1
    while used_columns[pivot_element.column]:
        pivot_element.column += 1
    while 0 == a[pivot_element.row][pivot_element.column] or used_rows[pivot_element.row]:
        pivot_element.row += 1
        if pivot_element.row > m - 1:
            return False, None
    return True, pivot_element


def SwapLines(a, b, used_rows, pivot_element):
    a[pivot_element.column], a[pivot_element.row] = a[pivot_element.row], a[pivot_element.column]
    b[pivot_element.column], b[pivot_element.row] = b[pivot_element.row], b[pivot_element.column]
    used_rows[pivot_element.column], used_rows[pivot_element.row] = used_rows[pivot_element.row], used_rows[
        pivot_element.column]
    pivot_element.row = pivot_element.column


def ProcessPivotElement(a, b, pivot_element):
    n = len(a)
    m = len(a[pivot_element.row])
    scale = a[pivot_element.row][pivot_element.column]
    for j in range(m):
        a[pivot_element.row][j] /= scale
    b[pivot_element.row] /= scale
    for i in range(n):
        if i != pivot_element.row:
            scale = a[i][pivot_element.column]
            for j in range(pivot_element.column, n):
                a[i][j] -= a[pivot_element.row][j] * scale
            b[i] -= b[pivot_element.row] * scale


def MarkPivotElementUsed(pivot_element, used_rows, used_columns):
    used_rows[pivot_element.row] = True
    used_columns[pivot_element.column] = True


def SolveEquation(equation):
    a = equation.a
    b = equation.b
    size = len(a)

    used_columns = [False] * size
    used_rows = [False] * size
    for _ in range(size):
        solved, pivot_element = Prime_element(a, used_rows, used_columns)
        if not solved:
            return False, None
        SwapLines(a, b, used_rows, pivot_element)
        ProcessPivotElement(a, b, pivot_element)
        MarkPivotElementUsed(pivot_element, used_rows, used_columns)

    return True, b


def addEquations(n, m, A, b, Big_number):
    for i in range(m):
        e = [0.0] * m
        e[i] = -1.0
        A.append(e)
        b.append(0.0)
    A.append([1.0] * m)
    b.append(Big_number)


def checkResult(n, m, A, b, c, result, lastEquation, ans, Best):
    for r in result:
        if r < -1e-3:
            return False, ans, Best
    for i in range(n):
        r = 0.0
        for j in range(m):
            r += A[i][j] * result[j]
        if r > b[i] + 1e-3:
            return False, ans, Best
    score = 0.0
    for j in range(m):
        score += c[j] * result[j]
    if score <= Best:
        return False, ans, Best
    else:
        if lastEquation:
            return True, 1, score
        else:
            return True, 0, score


def solve_diet_problemASAP(n, m, A, b, c, Big_number=VeryBigInteger):
    addEquations(n, m, A, b, Big_number)
    l = n + m + 1
    ans = -1
    Best = -float('inf')
    BestR = None
    for x in range(2 ** l):
        usedIndex = [i for i in range(l) if ((x / 2 ** i) % 2) // 1 == 1]
        if len(usedIndex) != m:
            continue
        lastEquation = False
        if usedIndex[-1] == l - 1:
            lastEquation = True
        As = [A[i] for i in usedIndex]
        bs = [b[i] for i in usedIndex]
        solved, result = SolveEquation(copy.deepcopy(Equation(As, bs)))
        if solved:
            isAccepted, ans, Best = checkResult(
                n, m, A, b, c, result, lastEquation, ans, Best)
            if isAccepted:
                BestR = result
    return [ans, BestR]


n, m = list(map(int, stdin.readline().split()))
A = []
for i in range(n):
    A += [list(map(int, stdin.readline().split()))]
b = list(map(int, stdin.readline().split()))
c = list(map(int, stdin.readline().split()))

anst, ansx = solve_diet_problemASAP(n, m, A, b, c)

if anst == -1:
    print("No solution")
if anst == 0:
    print("Bounded solution")
    print(' '.join(list(map(lambda x: '%.18f' % x, ansx))))
if anst == 1:
    print("Infinity")
