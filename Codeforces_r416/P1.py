def foo(a,b):
    p = 0
    q = 0
    for i in range(1,10*(a+1),1):
        if i*i > a:
            p = i-1
            break
    for i in range(1,10*(b+1),1):
        if i*(i+1) > b:
            q = i-1
            break
    # print p, q
    if p > q:
        print "Valera"
    elif p <= q:
        print "Vladik"

s = raw_input()
arr = s.split()
a = int(arr[0])
b = int(arr[1])
foo(a,b)
