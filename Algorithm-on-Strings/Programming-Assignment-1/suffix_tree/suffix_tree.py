# python3
import sys
sys.setrecursionlimit(1000)

def trie(text):
	tree = dict()
	keys = 1
	for i in range(0,len(text)):
		node = 0
		for j in range(i, len(text)):
			c = text[j]
			if node in tree:
				if c in tree[node]:
					node = tree[node][c]
				else:
					tree[node].update({c: keys})
					node = keys
					keys += 1
			else:
				tree[node] = {c: keys}
				node = keys
				keys += 1
	return tree


def build_suffix_tree(text):
    """
    Build a suffix tree of the string text and return a list
    with all of the labels of its edges (the corresponding 
    substrings of the text) in any order.
    """
    tree = trie(text)
    result = []
    #print(len(tree))
    #print(tree)
    #print(len(tree[0]))
    def rec_util(tree,node,patt=''):
        if node in tree:
            if len(tree[node])==1:
                for c in tree[node]:
                    patt+=c
                    v=tree[node][c]
                    rec_util(tree,v,patt)
            else:
                if len(patt)>0:
                    result.append(str(patt))
                for c in tree[node]:
                    rec_util(tree,tree[node][c],str(c))
        else:
            if len(patt)>0:
                result.append(str(patt))
    rec_util(tree,0,'')

    return result


if __name__ == '__main__':
    text = sys.stdin.readline().strip()
    result = build_suffix_tree(text)
    print("\n".join(result))
