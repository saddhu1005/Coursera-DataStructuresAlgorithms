# Uses python3
import sys

N = 1618

def checkIfOptimized(k, reads):
	k_mers = set()
	for read in reads:
		for i in range(0, len(read)-k+1):
			k_mers.add(read[i:i+k])
	prefix_set = set()
	suffix_set = set()
	for k_mer in k_mers:
		prefix_set.add(k_mer[:-1])
		suffix_set.add(k_mer[1:])
	return prefix_set == suffix_set


reads = []
for i in range(N):
	read = sys.stdin.readline().strip()
	reads.append(read)

for k in range(len(reads[2]), 1, -1):
	if checkIfOptimized(k, reads):
		print(k)
		break