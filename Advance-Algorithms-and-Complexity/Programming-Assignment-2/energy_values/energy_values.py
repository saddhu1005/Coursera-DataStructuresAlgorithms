# python3

EPS = 1e-6
PRECISION = 6

class Equation:
    def __init__(self, a, b):
        self.a = a
        self.b = b

class Position:
    def __init__(self, column, row):
        self.column = column
        self.row = row

def ReadEquation():
    size = int(input())
    a = []
    b = []
    for _ in range(size):
        line = list(map(float, input().split()))
        a.append(line[:size])
        b.append(line[size])
    return Equation(a, b)

def SelectPivotElement(a, used_rows, used_columns, step):
    # This algorithm selects the first free element.
    # You'll need to improve it to pass the problem.
    pivot_element = Position(step, step)
    size = len(used_rows)
    while used_columns[pivot_element.column] and pivot_element.column < size - 1:
        pivot_element.column += 1
    
    while ( a[pivot_element.row][pivot_element.column] ==0 or used_rows[pivot_element.row] ) and pivot_element.row < size - 1:
        pivot_element.row += 1
    while a[pivot_element.row][pivot_element.column] == 0 and pivot_element.column < size - 1:
        pivot_element.column += 1
        while pivot_element.column < size - 1 and used_columns[pivot_element.column]:
            pivot_element.column += 1
        pivot_element.row = step
        while (a[pivot_element.row][pivot_element.column] == 0 or used_rows[pivot_element.row]) and pivot_element.row < size - 1:
            pivot_element.row += 1

    return pivot_element
    

def SwapLines(a, b, used_rows, pivot_element):
    a[pivot_element.column], a[pivot_element.row] = a[pivot_element.row], a[pivot_element.column]
    b[pivot_element.column], b[pivot_element.row] = b[pivot_element.row], b[pivot_element.column]
    used_rows[pivot_element.column], used_rows[pivot_element.row] = used_rows[pivot_element.row], used_rows[pivot_element.column]
    pivot_element.row = pivot_element.column


def AddRows(a, b, row1, row2y, y):
    for i in range(len(a[row1])):
        a[row1][i] += a[row2y][i] * y
    b[row1] += b[row2y] * y
    pass


def ProcessPivotElement(a, b, pivot_element):
    # Write your code here
    size = len(a[pivot_element.row])
    x = a[pivot_element.row][pivot_element.column]
    for i in range(size):
        a[pivot_element.row][i]/= x
    b[pivot_element.row]/= x
    
    for i in range(size):
        if i == pivot_element.row:
            continue
        y = a[i][pivot_element.column]
        AddRows(a, b, i, pivot_element.row, y * -1)
    
    pass


def MarkPivotElementUsed(pivot_element, used_rows, used_columns):
    used_rows[pivot_element.row] = True
    used_columns[pivot_element.column] = True

def SolveEquation(equation):
    a = equation.a
    b = equation.b
    size = len(a)

    used_columns = [False] * size
    used_rows = [False] * size
    for step in range(size):
        pivot_element = SelectPivotElement(a, used_rows, used_columns, step)
        if a[pivot_element.row][pivot_element.column] == 0:
            continue
        SwapLines(a, b, used_rows, pivot_element)
        ProcessPivotElement(a, b, pivot_element)
        MarkPivotElementUsed(pivot_element, used_rows, used_columns)
    # for i in range(size):
    #     print(a[i], b[i])
    # print('')
    
    return b

def PrintColumn(column):
    size = len(column)
    for row in range(size):
        print("%.6lf" % round(column[row], 6), end = ' ')

if __name__ == "__main__":
    equation = ReadEquation()
    solution = SolveEquation(equation)
    PrintColumn(solution)
    exit(0)


