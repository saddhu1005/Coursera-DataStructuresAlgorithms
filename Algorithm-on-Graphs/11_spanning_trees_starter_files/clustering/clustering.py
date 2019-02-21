#Uses python3
import sys
import math
from operator import itemgetter
def distance(x1,y1,x2,y2):
    res=(y2-y1)**2 + (x2-x1)**2
    res=math.sqrt(res)
    return res
def find(x,parent):
    while parent[x]!=x:
        c=parent[x]
        parent[x]=parent[c]
        x=c
    return x

def union(x,y,parent):
    if x>y:
        parent[x]=y
    else:
        parent[y]=x
    pass

def Krushkal_MST(dist,n,k):
    parent=[0]*n
    for i in range(n):
        parent[i]=i
    count=n
    result=0.0
    #vals=[[0.0 for _ in range(n)] for _ in range(n)]
    vals=[]
    while count>k:
        w,x,y=dist.pop(0)
        x=find(x,parent)
        y=find(y,parent)
        if x==y:
            continue
        else :
            union(x,y,parent)
            count-=1
    while dist:
        w,x,y=dist.pop(0)
        x=find(x,parent)
        y=find(y,parent)
        if x==y:
            continue
        vals.append(w)
    vals.sort()
    result=vals[0]
    return result
def clustering(x, y, k):
    #dist=[[0.0 for _ in range(len(x))] for _ in range(len(x))]
    dist=[]
    for i in range(len(x)):
        for j in range(len(x)):
            d=distance(x[i],y[i],x[j],y[j])
            dist.append((d,i,j))
    dist.sort(key=itemgetter(0))
    dist=dist[len(x):]
    if(k>len(x)):
        return -1
    result=Krushkal_MST(dist,len(x),k)
    return result


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    data = data[1:]
    x = data[0:2 * n:2]
    y = data[1:2 * n:2]
    data = data[2 * n:]
    k = data[0]
    print("{0:.9f}".format(clustering(x, y, k)))

