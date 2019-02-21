# python3
import sys
sys.setrecursionlimit(10000)
class Node:
    def __init__(self, label):
        self.label = label
        self.child = {}


class SuffixTree:
    def __init__(self, text):
        self.root = Node(None)
        self.root.child[text[0]] = Node(text)
        for i in range(1, len(text)):
            current = self.root
            j = i
            while j<len(text):
                if text[j] in current.child:
                    k = j + 1
                    child = current.child[text[j]]
                    label = child.label
                    while k<len(text) and k - j < len(label) and text[k] == label[k - j]:
                        k += 1
                    # if k == len(text):
                    #    print("Fuck You",label)
                    if k - j == len(label):
                        current = child
                        j = k
                    else:
                        contains, new = label[k-j], text[k]
                        newchild = Node(label[:k-j])
                        child.label = label[k-j:]
                        newchild.child[new] = Node(text[k:])
                        newchild.child[contains] = child
                        current.child[text[j]] = newchild
                        break
                else:
                    current.child[text[j]] = Node(text[j:])
                    break


def build_suffix_tree(text):
    """
    Build a suffix tree of the string text and return a list
    with all of the labels of its edges (the corresponding 
    substrings of the text) in any order.
    """
    tree = SuffixTree(text)
    return tree 
    #print(len(tree))
    #print(tree)
    #print(len(tree[0]))
def print_dfs(root):
    for child in root.child:
        print(root.child[child].label)
        print_dfs(root.child[child])

    

if __name__ == '__main__':
    text = sys.stdin.readline().strip()
    result = build_suffix_tree(text)
    print_dfs(result.root)
    #print(result)
