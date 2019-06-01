# Uses python3
N = 1618
MIN_LENGTH = 69
LENGTH = 100

class TrieNode(object):
	def __init__(self):
		self.children = {}
		self.indexes = []


class PrefixTrie(object):
	def __init__(self):
		self.root = TrieNode()

	def addPrefix(self, string, index):
		for e in range(MIN_LENGTH, len(string)):
			reversed_prefix = string[:e][::-1]
			node = self.root
			for char in reversed_prefix:
				if char not in node.children:
					node.children[char] = TrieNode()
				node = node.children[char]
			node.indexes.append(index)


	def matching(self, string):
		adj = []
		node = self.root
		length = 0

		for char in string[::-1]:
			if char not in node.children:
				break
			node = node.children[char]
			length += 1
			if length >= MIN_LENGTH and node.indexes:
				for index in node.indexes:
					adj.append((index, length))
		return adj


def overlapValue(s,t):
	for i in range(LENGTH, 0, -1):
		if s[LENGTH-i:] == t[:i]: return i
	return 0


def overlapGraph(reads):
	prefixTrie = PrefixTrie()

	for i, read in enumerate(reads):
		prefixTrie.addPrefix(read, i)
	adj = [[] for _ in range(len(reads))]

	for i, read in enumerate(reads):
		adj[i] = prefixTrie.matching(read)

	for l in adj:
		l.sort(key=lambda x: x[1], reverse=True)
	return adj 


def longestHamiltonianPath(adj):
	current = 0
	added = set([0])
	path = [(0, 0)]
	while len(added)<len(adj):
		for i, link in enumerate(adj[current]):
			if link[0] not in added:
				added.add(link[0])
				current = link[0]
				path.append(link)
				break
	return path


def assembleGenome(path, reads):
	genome = ""
	for node in path:
		genome += reads[node[0]][node[1]:]
	genome = genome[:-overlapValue(reads[path[-1][0]], reads[0])]
	return genome

reads = []
for i in range(N):
	reads.append(input())
reads = list(set(reads))
adj = overlapGraph(reads)
path = longestHamiltonianPath(adj)
genome = assembleGenome(path, reads)
print(genome)