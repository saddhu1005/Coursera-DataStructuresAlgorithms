# python3
import sys


def build_suffix_array(text):
  """
  Build suffix array of the string text and
  return a list result of the same length as the text
  such that the value result[i] is the index (0-based)
  in text where the i-th lexicographically smallest
  suffix of text starts.
  """
  result = []
  n = len(text)
  sarray = [None] * n
  for i in range(len(text)):
    sarray[i] = (text[i: n], i)
  sarray = sorted(sarray)
  # Implement this function yourself
  for array in sarray:
    result.append(array[1])
  return result


if __name__ == '__main__':
  text = sys.stdin.readline().strip()
  print(" ".join(map(str, build_suffix_array(text))))
