def foo(a,b,c,d):
    count = 0
    # a1 = [x for x in a if x <= b[0]]
    # c1 = [y for y in c if y <= b[0]]
    a1 = []
    # a1.append(a[0])
    for i in xrange(0,d[0]):
        if(i == 0):
            a1.append(a[i])
        else:
            a1.append(a[i]+a1[-1])
    c1 = []
    # c1.append(c[0])
    for i in xrange(0,d[2]):
        if(i == 0):
            c1.append(c[i])
        else:
            c1.append(c[i]+c1[-1])
    # print a1, c1
    m=0
    n=0
    for i in b:
        while(m < d[0] and a[m] <= i):
            m += 1
        while(n < d[2] and c[n] <= i):
            n += 1
        if m != 0 and n != 0:
            p = (m*i+a1[m-1])*(n*i+c1[n-1])
        else:
            p = 0
        # print a1
        # print c1
        # p = ((len(a1)*i+sum(a1))%(10**9+7)*(len(c1)*i+sum(c1))%(10**9+7))%(10**9+7)
        # print p
        count = ((count)+(p%(10**9+7)))%(10**9+7)
    return count

t = input()
for i in xrange(0,t):
    lengths = raw_input()
    lengths = map(int,lengths.split())
    a = raw_input()
    a = map(int,a.split())
    a.sort()
    b = raw_input()
    b = map(int,b.split())
    b.sort()
    c = raw_input()
    c = map(int,c.split())
    c.sort()
    print foo(a,b,c,lengths)