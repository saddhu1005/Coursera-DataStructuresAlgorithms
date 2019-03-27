# python3
import sys


def prefixfunction(pattern):
  s = [None] * len(pattern)
  border = 0
  s[0] = 0
  for i in range(1, len(pattern)):
    while border > 0 and pattern[i] != pattern[border]:
      border=s[border - 1]
    if pattern[i] == pattern[border]:
      border += 1
    else:
      border = 0
    s[i] = border
  return s
    

def find_pattern(pattern, text):
  """
  Find all the occurrences of the pattern in the text
  and return a list of all positions in the text
  where the pattern starts in the text.
  """
  result = []
  # Implement this function yourself
  p  = prefixfunction(pattern + '$' + text)
  for i in range(len(pattern), len(p)):
    if p[i] == len(pattern):
      result.append(i - 2 * len(pattern))
  return result


if __name__ == '__main__':
  pattern = sys.stdin.readline().strip()
  text = sys.stdin.readline().strip()
  result = find_pattern(pattern, text)
  print(" ".join(map(str, result)))