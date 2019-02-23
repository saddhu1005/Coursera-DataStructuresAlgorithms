# python3
import sys


def InverseBWT(bwt):
    # write your code here
    result = ""
    n = len(bwt)
    first = ''
    count = [0] * 255
    for ch in bwt:
        count[ord(ch)] += 1
    for i in range(0, 255):
        while count[i]:
            first += chr(i)
            count[i] -= 1
    for i in range(n):
        if bwt[i] is '$':
            start = i
            break
    l_shift = [None] * n
    sarr = [[] for _ in range(255)]
    index = [0] * 255
    for i in range(n):
        sarr[ord(bwt[i])].append(i)
    for i in range(n):
        j = ord(first[i])
        l_shift[i] = sarr[j][index[j]]
        index[j] += 1
    for i in range(n):
        start = l_shift[start]
        result += bwt[start]
    return result


if __name__ == '__main__':
    bwt = sys.stdin.readline().strip()
    print(InverseBWT(bwt))
