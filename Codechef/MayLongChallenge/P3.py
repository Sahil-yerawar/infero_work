def maxMedian1(n,p):
    if p == 1:
        print max(n)
        for i in n:
            print i,
    else:
        n = sorted(n)
        x = 0
        y = p
        m = []
        for i in range(0,p*2,1):
            if i%2 == 0:
                m.append(n[x])
                x += 1
            else:
                m.append(n[y])
                y += 1
        print max(m[p-1:p+1])
        for i in m:
            print i,

n = input()
for i in range(0,n):
    p = input()
    l = []
    array = raw_input()
    array = array.split()
    for i in array:
        l.append(int(i))
    maxMedian1(l,p)