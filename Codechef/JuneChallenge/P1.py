list1 = []
x = 1
while x < 500:
    # x = list1[-1]+list1[-2]+1
    list1.append(x)
    x += 10
x = 3
while x < 500:
    list1.append(x)
    x += 10

n = input()
p = []
for i  in xrange(0,n):
    t = input()
    p = list1[:t]
    print(" ".join(map(str,p)))
    # print "\n"