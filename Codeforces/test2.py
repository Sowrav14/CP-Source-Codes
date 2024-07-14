
for n in range(1, 2):
    for a in range(1, 10000):
        for b in range(1, min(10000, n*a)):
            x = n * a - b
            n_ = str(n)
            a_ = n_ * a
            b_ = str(b)
            y = 0
            if(len(a_) > len(b_)): y = a_[ : -b]
            if(x == y) : print(n, a, b)