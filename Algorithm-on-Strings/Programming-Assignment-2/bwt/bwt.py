# python3
import sys

def BWT(text):
    result = ""
    n = len(text)
    sarray = [None] * n
    for i in range(len(text)):
        sarray[i] = (text[i : n], i)
        # print(sarray[i])
    sarray = sorted(sarray)
    for array in sarray:
        i = (n + array[-1] - 1) % n
        result += text[i]
    return result

if __name__ == '__main__':
    text = sys.stdin.readline().strip()
    print(BWT(text))
