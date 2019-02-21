# python3
import sys

NA = -1

class Node:
	def __init__ (self):
		self.next = [NA] * 4
def trie(patterns,n):
	tree = dict()
	keys=1
	for pattern in patterns:
		node=0
		pattern += '$'
		for c in pattern:
			if node in tree:
				if c in tree[node]:
					node=tree[node][c]
				else:
					tree[node].update({c:keys})
					node = keys
					keys += 1
			else:
				tree[node]={c:keys}
				node = keys
				keys += 1
	return tree


def solve (text, n, patterns):
	result = []
	tree = trie(patterns,n)
	#print(tree)
	text+='$'
	for i in range(len(text)):
		node=0
		for j in range(i,len(text)):
			if node in tree:
				if '$' in tree[node]:
					result.append(i)
					'''for key in tree[node]:
						if key is not '$':
							node=tree[node][key]
							break'''
					break
				elif text[j] in tree[node]:
					node=tree[node][text[j]]
				else:
					break


	return result

text = sys.stdin.readline ().strip ()
n = int (sys.stdin.readline ().strip ())
patterns = []
for i in range (n):
	patterns += [sys.stdin.readline ().strip ()]

ans = solve (text, n, patterns)

sys.stdout.write (' '.join (map (str, ans)) + '\n')

