import sys
from collections import defaultdict

class TrieNode:
    def __init__(self):
        self.word = False
        self.children = defaultdict(TrieNode)

class Trie:
    def __init__(self):
        self.root = TrieNode()
    def insert(self,word):
        node = self.root
        for char in word:
            node = node.children[char]
        node.word = True
    def search(self,word):
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
            if node.word:
                return True
        return node.word

input = sys.stdin.readline
t = int(input().rstrip())
for _ in range(t):
    n = int(input().rstrip())
    words = []
    for __ in range(n):
        words.append(input().rstrip())
    words.sort(key=lambda x: len(x))
    my_trie = Trie()
    possible = True
    for word in words:
        if my_trie.search(word):
            print("NO")
            possible = False
            break
        my_trie.insert(word)
    if possible:
        print("YES")