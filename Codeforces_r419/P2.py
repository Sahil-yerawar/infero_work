x = raw_input()
x = map(int,x.split())
n = x[0]
k = x[1]
q = x[2]
ranges = []
mins = []
maxs = []
for i in xrange(0,n):
    p = raw_input()
    p = map(int,p.split())
    mins.append(p[0])
    maxs.append(p[1])
    ranges.append(p)

mini = min(mins)
maxi = max(maxs)
# print mini, maxi
accept = []
for i in xrange(mini,maxi+1):
    count = 0
    for j in xrange(0,len(ranges)):
        if ranges[j][0]<=i and i <=ranges[j][1]:
            count += 1
    if count >= k:
        accept.append(i)
for i in xrange(0,q):
    p = raw_input()
    p = map(int,p.split())
    count = 0
    for j in xrange(0,len(accept)):
        if p[0] <= accept[j] and accept[j] <= p[1]:
            count += 1
    print count