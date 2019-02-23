# python3
import sys

def comp(c):
  ch = ord(c)
  if ch == 36:
    return 0
  elif ch == 65:
    return 1
  elif ch == 67:
    return 2
  elif ch ==  71:
    return 3
  else:
    return 4


def comc(ch):
  if ch == 0:
    return '$'
  elif ch == 1:
    return 'A'
  elif ch == 2:
    return 'C'
  elif ch == 3:
    return 'G'
  else:
    return 'T'
def PreprocessBWT(bwt):
  """
  Preprocess the Burrows-Wheeler Transform bwt of some text
  and compute as a result:
    * starts - for each character C in bwt, starts[C] is the first position 
        of this character in the sorted array of 
        all characters of the text.
    * occ_count_before - for each character C in bwt and each position P in bwt,
        occ_count_before[C][P] is the number of occurrences of character C in bwt
        from position 0 to position P inclusive.
  """
  # Implement this function yourself
  n = len(bwt)
  starts = [-1] * 5
  first = ''
  count = [0] * 5
  occ_counts_before = [[0] * (n + 1) for _ in range(5)]
  for ch in bwt:
    count[comp(ch)] += 1
  for i in range(5):
    while count[i]:
      first += comc(i)
      count[i] -= 1
  for i in range(n):
    if starts[comp(first[i])] == -1:
      starts[comp(first[i])] = i
  occ_counts_before[comp(bwt[0])][1] = 1
  for i in range(1, n):
    occ_counts_before[0][i + 1] = occ_counts_before[0][i]
    occ_counts_before[1][i + 1] = occ_counts_before[1][i]
    occ_counts_before[2][i + 1] = occ_counts_before[2][i]
    occ_counts_before[3][i + 1] = occ_counts_before[3][i]
    occ_counts_before[4][i + 1] = occ_counts_before[4][i]
    j = comp(bwt[i])
    occ_counts_before[j][i + 1] += 1
  return starts, occ_counts_before


def CountOccurrences(pattern, bwt, starts, occ_counts_before):
  """
  Compute the number of occurrences of string pattern in the text
  given only Burrows-Wheeler Transform bwt of the text and additional
  information we get from the preprocessing stage - starts and occ_counts_before.
  """
  # Implement this function yourself
  top, bottom = 0, len(bwt) - 1
  while top <= bottom:
    if len(pattern) > 0:
      symbol = comp(pattern[-1])
      pattern = pattern[0:-1]
      if comp(bwt[top]) == symbol or (occ_counts_before[symbol][bottom + 1] - occ_counts_before[symbol][top]) > 0:
        top = starts[symbol] + occ_counts_before[symbol][top]
        bottom = starts[symbol] + occ_counts_before[symbol][bottom + 1] - 1
      else:
        return 0
    else:
      return bottom - top + 1
  return 0
     

if __name__ == '__main__':
  bwt = sys.stdin.readline().strip()
  pattern_count = int(sys.stdin.readline().strip())
  patterns = sys.stdin.readline().strip().split()
  # Preprocess the BWT once to get starts and occ_count_before.
  # For each pattern, we will then use these precomputed values and
  # spend only O(|pattern|) to find all occurrences of the pattern
  # in the text instead of O(|pattern| + |text|).  
  starts, occ_counts_before = PreprocessBWT(bwt)
  occurrence_counts = []
  # print(starts[0], starts[1], starts[2], starts[3], starts[4])
  # print(occ_counts_before[0], occ_counts_before[1], occ_counts_before[2], occ_counts_before[3], occ_counts_before[4])
  for pattern in patterns:
    occurrence_counts.append(CountOccurrences(pattern, bwt, starts, occ_counts_before))
  print(' '.join(map(str, occurrence_counts)))
