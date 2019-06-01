#Uses python3

from collections import defaultdict   
import itertools

binary_inp = int(input())
l_pos = binary_inp - 1

last_binary ='1' * binary_inp
bin_int = int(last_binary, 2)

last = "1" + ('0' * l_pos)
first = '0' * binary_inp
nodes = defaultdict(list)

for i in range(0,bin_int+1):
		a = (bin(i)[2:].zfill(binary_inp))
		if (a != last and a != first):
			start = a[0:l_pos]
			end = a[1:binary_inp]
			nodes[start].append(end)
			nodes[end].append(start)

start = '0' * (binary_inp - 1)
visits = [start]
current = start

while(len(nodes[current])>0):
	suffix = current[1:]
	nxt_char = "1" if suffix + "1" in nodes[current] else "0"
	visits.append(suffix+nxt_char)
	nodes[current].remove(suffix + nxt_char)
	nodes[suffix+nxt_char].remove(current)
	current = suffix+nxt_char  

result ='0'
for i,dig in enumerate(visits):
   result += dig[0]

print(result)