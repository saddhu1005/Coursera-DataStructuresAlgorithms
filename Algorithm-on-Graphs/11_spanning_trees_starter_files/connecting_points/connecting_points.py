#Uses python3
import sys
import math
import heapq
def distance(x1,y1,x2,y2):
    res=(y2-y1)**2 + (x2-x1)**2
    res=math.sqrt(res)
    return res
def prims_mst(dist,n):
    result=0.0
    heap=[]
    inheap=[True]*n
    val=[(10**11)+1.5]*n
    s=0
    heapq.heappush(heap,(0.0,s))
    val[s]=0.0
    while heap:
        w,s=heapq.heappop(heap)
        if w!=val[s]:
            continue
        inheap[s]=False
        for i in range(n):
            if i==s:
                continue
            if inheap[i]==True and val[i]>dist[s][i]:
                val[i]=dist[s][i]
                heapq.heappush(heap,(val[i],i))
    for i in range(n):
        result=result + val[i]
    return result


def minimum_distance(x, y):
    result = 0.0
    dist=[[0.0 for _ in range(len(x))] for _ in range(len(x))]
    for i in range(len(x)):
        for j in range(len(x)):
            d=distance(x[i],y[i],x[j],y[j])
            dist[i][j]=d
    result=prims_mst(dist,len(x))
    return result


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    x = data[1::2]
    y = data[2::2]
    print("{0:.9f}".format(minimum_distance(x, y)))
