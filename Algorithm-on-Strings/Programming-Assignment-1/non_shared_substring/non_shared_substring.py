# python3
import sys

sys.setrecursionlimit(10000)

class SuffixTree:

	class Node:
		def __init__(self, label):
			self.label = label
			self.child = {}

	def __init__ (self, text):
		self.root = self.Node(None)
		self.root.child[text[0]] = self.Node(text)
		self.c = 0
		for i in range(1, len(text)):
			current = self.root
			j = i
			while j < len(text):
				self.c += 1
				if text[j] in current.child:
					child = current.child[text[j]]
					label = child.label
					k = j + 1
					while k - j <len(label) and text[k] == label[k - j]:
						k += 1
						self.c += 1
					if k - j == len(label):
						current = child
						j = k
					else:
						exist, new = label[k - j], text[k]
						newchild = self.Node(label[:k - j])
						newchild.child[new] = self.Node(text[k:])
						newchild.child[exist] = child
						child.label = label[k - j:]
						current.child[text[j]] = newchild
						break
				else:
					current.child[text[j]] = self.Node(text[j:])
					break


class Non_shared_Substr:
	def __init__ (self, root, text):
		self.start = 0
		self.length = 1<<30
		self.c = 0
		for i in range(len(text)):
			current = root
			j = i
			while j < len(text):
				# print('BUG here'+ str(j))
				self.c += 1
				if text[j] in current.child:
					child = current.child[text[j]]
					label = child.label
					k = j + 1
					while k < len(text) and k - j < len(label) and text[k] == label[k - j]:
						k += 1
						self.c += 1
						if k - j + 1 >= self.length:
							k = len(text)
							break

					if k == len(text):
						break
					if k - j == len(label):
						current = child
						j = k
					else:
						if k - i + 1 < self.length:
							self.length = k - i + 1
							self.start = i
						break
				else:
					if j - i + 1< self.length:
						self.length = j - i + 1
						self.start = i
					break




def print_tree (root):
	for child in root.child:
		print(root.child[child].label)
		print_tree(root.child[child])


def solve (p, q):
	result = p
	q = q + '#'
	tree = SuffixTree(q)
	# print_tree(tree.root)
	result = Non_shared_Substr(tree.root, p)
	# print(tree.c,result.c)
	return p[result.start : result.start + result.length]

p = sys.stdin.readline ().strip ()
q = sys.stdin.readline ().strip ()

ans = solve (p, q)

sys.stdout.write (ans + '\n')
