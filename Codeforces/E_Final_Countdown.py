t = int(input())
for i in range(t):
    n = int(input())
    s = input()
    llist = []
    for j in range(n):
       temp = s[:j+1] 
       temp = int(temp);
       llist.append(temp)
    
    prev = 0
    ans = 0
    k = n
    for j in range(n):
        llist[j] = llist[j] - prev;
        prev += llist[j];
        # print(llist[j], (k))
        ans = ans + (llist[j] * (k))
        k = k  - 1
    print(ans)