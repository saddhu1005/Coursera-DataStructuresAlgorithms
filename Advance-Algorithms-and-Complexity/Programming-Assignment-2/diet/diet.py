# python3
from sys import stdin
import scipy as sp
import scipy.optimize

def pivet_op(mat, row, col):
  pivet = mat[row][col]
  for j in range(0, len(mat[0])):
    mat[row][j] = mat[row][j] / pivet
  
  i = 0
  for i in range(len(mat)):
    if i == row:
      continue
    ratio = mat[i][col]
    for j in range(len(mat[0])):
      mat[i][j] -= (ratio * mat[row][j])
    
  return mat


def simplex(mat, XS):
  anst = 0
  opt = False
  n = len(mat)
  m = len(mat[0])

  while (not opt) and (anst == 0):
    mi = 0.0
    pi_col = 0
    j = 1
    while j < m - n + 1:
      cj = mat[0][j] * 1.0
      
      if cj < mi:
        mi = cj
        pi_col = j
      j += 1
    if mi == 0.0:
      opt = True
      continue

    pi_row = i = 0
    min_val = 10 ** 15

    for xi in mat:
      if i == 0:
        i += 1
        continue
      xij = xi[pi_col]
      if xij > 0:
        loc_min = xi[0]/ xij
        if loc_min > 0 and (loc_min < min_val or min_val == 10 ** 15):
          min_val = loc_min
          pi_row = i
      i += 1
    if min_val == 10 ** 15:
      anst = 1
      continue
    #print(pi_row, pi_col)
    mat = pivet_op(mat, pi_row, pi_col)
    XS[pi_col - 1] = mat[pi_row][0]
    '''
    print('\n----')
    for row in mat:
      print(row)
    print('----\n')
    #'''
  print('\n----')
  for row in mat:
    print(row)
  print('----\n')
  return [anst, XS[0:m - n]]


def solve_diet_problem(n, m, A, b, c):  
  # Write your code here
  mat = [[0 for _ in range(n + m + 1)] for _ in range(n + 1)]
  XS = [0] * (m + n)
  for i in range(m, m + n):
    XS[i] = b[i - m]

  mat[0][0] = 0
  for i in range(1, m + 1):
    mat[0][i] = (-1 * c[i - 1])
  for i in range(m + 1, m + n + 1):
    mat[0][i] = 0
  
  for i in range(1, n + 1):
    mat[i][0] = b[i - 1]
    for j in range(1,m + 1):
      mat[i][j] = A[i - 1][j - 1]
    for j in range(m + 1, n + m + 1):
      if j == m + i:
        mat[i][j] = 1
      else:
        mat[i][j] = 0

  return simplex(mat, XS)


def solve_diet_problem0(n, mm, A, b, c):

    cmin = [-1 * x for x in c]
    # built in function in scipy and numpy module to solve linear programming   
    res = sp.optimize.linprog(cmin, A, b)
    if 3 == res.status:
        ans = 1
        x = None
    elif 0 == res.status:
        ans = 0
        x = list(res.x)
    else:
        ans = -1
        x = None
    return ans, x


n, m = list(map(int, stdin.readline().split()))
A = []
for i in range(n):
  A += [list(map(int, stdin.readline().split()))]
b = list(map(int, stdin.readline().split()))
c = list(map(int, stdin.readline().split()))

anst, ansx = solve_diet_problem0(n, m, A, b, c)

if anst == -1:
  print("No solution")
if anst == 0:  
  print("Bounded solution")
  print(' '.join(list(map(lambda x : '%.18f' % round(x, 18), ansx))))
if anst == 1:
  print("Infinity")

