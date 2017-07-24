def foo(a,b):
    c = a[::-1]
    flag = c[0]
    j = 0
    p =0
    for i in xrange(0,b):
        if i != 0:
            c[i] += c[i-1]
            if c[i]*(i+1)>=flag:
                flag = c[i]*(i+1)
            else:
                j = i
                break
        if i == b-1:
            p = 1

    if p == 1:
        return flag
    else:
        for i in xrange(0,b-j):
            flag += a[i]
        return flag

t = input()
for i in xrange(0,t):
    n = input()
    x = raw_input()
    x = map(int,x.split())
    x.sort()
    print foo(x,n)