
N = int(1e5+10)
tree = [] * 4*N
val = [] * N

def build(node, l, r):
    if(l == r):
        node[l] = val[l]
        return
    m = int((l + r) / 2)
    build(2*node, l, m)
    build(2*node+1, m+1, r)
    tree[node] = tree[2*node] + tree[2*node+1]
    
def update(node, l, r, i):
    if(l == r):
        if(val[i] == 0):
            val[i] = 1
        else:
            val[i] = 1
        return
    m = int((l + r) / 2)
    
    if(i < m):
        update(2*node, l, m, i)
    else:
        update(2*node+1, m+1, r, i)
    tree[node] = tree[2*node] + tree[2*node]
    
def query(node, l, r, i):
    if(l == r):
        return l
    
    m = int((l + r) / 2)
    
    if(i <= m):
        return query(2*node, l, m, i)
    else:
        return query(2*node+1, m+1, r, i)



n = int(input())
temp = list(input().split())
for i in range(n):
    x = int(temp[i])
    val[i] = x
    
build(0, 0, n-1)
q = input(int())
for i in range(q):
    type = int(input())
    idx = int(input())
    if(type == 1):
        update(0, 0, n-1, idx)
    else:
        print(query(0, 0, n-1, idx))

