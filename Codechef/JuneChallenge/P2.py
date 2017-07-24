t =input()
for i in xrange(0,t):
    x = raw_input()
    x = map(int,x.split())
    u = x[0]
    v = x[1]
    print 1+((u+1)*(u+2))/2-1+(v*(2*u+v+1))/2