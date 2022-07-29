import sys
from collections import defaultdict
input = sys.stdin.readline

class Node:
    def __init__(self):
        self.end = False
        self.word = None
        self.children = defaultdict(Node)

class Trie:
    def __init__(self):
        self.root = Node()
    
    def insert(self,words):
        node = self.root
        for word in words:
            node = node.children[word]
            node.word = word
        node.end = True

n = int(input().rstrip())
trie = Trie()
for _ in range(n):
    trie.insert(list(map(str,input().split()))[1:])
    
stack = []
stack.append((trie.root,-1))

while stack:
    node,depth = stack.pop()
    if node.word:
        print('--'*depth + node.word)
    if not node.end:
        for k,v in sorted(node.children.items(),reverse=True):
            stack.append((v,depth+1))
