class Node:
    def __init__(self, idx=None):
        self.idx = idx
        self.left = None       # left -> 0
        self.right = None      # right -> 1

def insert(x, p):
    cur = root
    x_bin = bin(x)[2:]           # 补齐
    for i in x_bin:
        i = int(i)
        if i == 0:
            if not cur.left: cur.left = Node()
            cur = cur.left
        else:
            if not cur.right: cur.right = Node()
            cur = cur.right
    cur.idx = p

def query(x):
    cur = root
    x_bin = bin(x)[2:]
    for i in x_bin:
        i = int(i)
        if i == 0:
            if cur.right: cur = cur.right
            else: cur = cur.left
        else:
            if cur.left: cur = cur.left
            else: cur = cur.right
    return cur.idx



root = Node()
insert(x, p)
query(x)