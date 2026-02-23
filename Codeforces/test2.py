
n = int(input())
f = 1
for i in range(1, n + 1):
    f = f * i
    f = f % 998244353
print(f)