from collections import defaultdict

class Node:
    def __init__(self,char):
        self.char = char
        self.children = defaultdict(Node)
        self.count = defaultdict(int)
        self.isword = False
        
class Trie:
    def __init__(self):
        self.root = Node(None)
        
    def insert(self,word):
        cur = self.root
        cur.count[len(word)] += 1
        
        for c in word:
            if c not in cur.children:
                cur.children[c] = Node(c)
            cur = cur.children[c]
            cur.count[len(word)] += 1
            
        cur.isword = True
    
    def search(self,word):
        cur = self.root
        
        for c in word:
            if c == '?':
                break
            if c in cur.children:
                cur = cur.children[c]
            else:
                return 0
        return cur.count[len(word)]
    
def solution(words, queries):
    trie = Trie()
    r_trie = Trie()
    
    r_words = [w[::-1] for w in words]
    dic = {}
    answer = []

    for word in words:
        trie.insert(word)
    for word in r_words:
        r_trie.insert(word)
    for query in queries:
        if query in dic:
            answer.append(dic[query])
            continue
        if query.endswith("?"):
            result = trie.search(query)
            answer.append(result)
            dic["query"] = result

        else:
            result = r_trie.search(query[::-1])
            answer.append(result)
            dic["query"] = result

    return answer