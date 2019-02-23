# python3
import sys


def InverseBWT(bwt):
    # write your code here
    result = ""
    n = len(bwt)
    first = [None] * n
    count = [0] * 255
    for ch in bwt:
        count[ord(ch)] += 1
    ind = 0
    for i in range(0, 255):
        j = 0

        while count[i]:
            first[ind] = (chr(i), j)
            ind += 1
            j += 1
            count[i] -= 1
    last = [None] * n
    for i in range(n):
        last[i] = (bwt[i], count[ord(bwt[i])])
        count[ord(bwt[i])] += 1
    tup = last[0]
    result += '$'
    while True:
        result += tup[0]
        if len(result) >= n:
            break
        start, end = 0, n - 1
        while start <= end:
            mid = start + (end - start )//2
            fup = first[mid]
            # print(fup)
            if fup[0] == tup[0]:
                if fup[1] == tup[1]:
                    tup = last[mid]
                    # print(first[mid])
                    break
                elif fup[1] < tup[1]:
                    start = mid + 1
                else:
                    end = mid - 1
            elif fup[0] < tup[0]:
                start = mid + 1
            else:
                end = mid - 1
    return result[:: - 1]


if __name__ == '__main__':
    bwt = sys.stdin.readline().strip()
    print(InverseBWT(bwt))