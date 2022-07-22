import sys
input = sys.stdin.readline
sys.setrecursionlimit(20_000)
class node:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None

class Tree:

    def __init__(self):
        self.root = None

    def preorder(self,cur):
        if not cur:
            return
        
        print(cur.val)
        self.preorder(cur.left)
        self.preorder(cur.right)

    def postorder(self,cur):
        if not cur:
            return
        self.postorder(cur.left)
        self.postorder(cur.right)
        print(cur.val)
    
    def insert(self,val):
        new_node = node(val)

        cur = self.root
        if not cur:
            self.root = new_node
            return
        while True:
            if new_node.val < cur.val:
                if not cur.left:
                    cur.left = new_node
                    return
                else:
                    cur = cur.left
            else:
                if not cur.right:
                    cur.right = new_node
                    return
                else:
                    cur = cur.right

t = Tree()
while True:
    try:
        t.insert(int(input().rstrip()))
    except:
        break

t.postorder(t.root)