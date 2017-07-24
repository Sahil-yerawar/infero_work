n = input()
x = raw_input()
x = map(int,x.split())
m = input()

p = []
for i in xrange(0,m):
    y = raw_input()
    y1 = map(int,y.split())
    p.append(y1)

if p[m-1][1]-p[0][0] + 1 < sum(x):
    print -1
else:
    f = sum(x)
    for i in p:
        if i[0] <= f-p[0][0]+1 and i[1] >= f-p[0][0]+1:
            print f
            break
        elif i[0] >= f-p[0][0]+1 and i[1] >= f-p[0][0]+1:
            print i[0]
            break