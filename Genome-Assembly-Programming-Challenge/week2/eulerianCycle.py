#Uses python3

dataset = input().split()
n = int(dataset[0])
m = int(dataset[1])
edges = []
for i in range(m):
	edges.append(list(map(int, input().split())))
adj = [[] for _ in range(n)]
num = 0
for (a, b) in edges:
	adj[a - 1].append(((b - 1), num))
	num += 1


def solution():
	degrees = [0] * n
	for start, end in edges:
		degrees[start - 1] += 1
		degrees[end - 1] -= 1
	if any(degrees):
		print(0)
	else:
		path = [0]
		visited = set()
		while len(visited) < len(edges):
			for i, pt in enumerate(path):
				visflag = True
				for npt in adj[pt]:
					if npt[1] not in visited:
						visflag = False
						break
				if visflag:
					continue
				new_cycle = [pt]
				current = pt
				is_next = True
				while is_next:
					is_next = False
					for npt in adj[current]:
						if npt[1] not in visited:
							visited.add(npt[1])
							new_cycle.append(npt[0])
							current = npt[0]
							is_next = True
							break
				break
			path = path[:i]+new_cycle+path[i+1:]
		path = list(map(lambda x: str(x+1), path))[:-1]
		print(1)
		print(" ".join(path))
	pass


solution()