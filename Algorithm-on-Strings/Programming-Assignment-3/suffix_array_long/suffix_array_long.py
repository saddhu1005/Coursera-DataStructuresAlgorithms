# python3
import sys


def sortcharecters(text):
  count = [0] * 255
  order = [None] * len(text)
  for c in text:
    count[ord(c)] += 1
  for i in range(255):
    count[i] += count[i - 1]
  for i in range(len(text)-1,-1,-1):
    count[ord(text[i])] -= 1
    order[count[ord(text[i])]] = i
  return order


def singleclass(order, text):
  clas = [None] * len(text)
  clas[order[0]] = 0
  for i in range(1, len(text)):
    if text[order[i]] != text[order[i - 1]]:
      clas[order[i]] = clas[order[i-1]] + 1
    else:
      clas[order[i]] = clas[order[i-1]]
  return clas


def doubleorder(L, text, order, clas):
  n = len(text)
  count = [0] * n
  neworder = [None] * n
  for i in range(0, n):
    count[clas[i]] += 1
  for i in range(1, n):
    count[i] += count[i - 1]
  for i in range(n - 1, -1, -1):
    start = (order[i] - L + n) % n
    count[clas[start]] -= 1
    neworder[count[clas[start]]] = start
  return neworder


def updateclass(L, order, clas):
  n = len(clas)
  newclass = [None] * n
  newclass[order[0]] = 0
  for i in range(1, n):
    cur, prev = order[i], order[i - 1]
    mid, midprev = (cur + L) %  n, (prev + L) % n
    if clas[cur] != clas[prev] or clas[mid] != clas[midprev]:
      newclass[cur] = newclass[prev] + 1
    else:
      newclass[cur] = newclass[prev]
  return newclass 


def build_suffix_array(text):
  """
  Build suffix array of the string text and
  return a list result of the same length as the text
  such that the value result[i] is the index (0-based)
  in text where the i-th lexicographically smallest
  suffix of text starts.
  """
  #result = []
  # Implement this function yourself
  order = sortcharecters(text)
  clas = singleclass(order, text)
  L = 1
  while L < len(text):
    order = doubleorder(L, text, order, clas)
    clas = updateclass(L, order, clas)
    L *= 2
  return order


if __name__ == '__main__':
  text = sys.stdin.readline().strip()
  print(" ".join(map(str, build_suffix_array(text))))
