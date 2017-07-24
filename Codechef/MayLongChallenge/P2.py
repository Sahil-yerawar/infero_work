def maxCourses(n,p):
    result = max(n)
    # l = []
    # for i in range(1,p+1):
    #     l.append(i)
    # for i in range(1,p+1):
    #     for j in range(1,n[i-1]+1):
    #         if j in l:
    #             l.remove(j)
    return p-result

n = input()
for i in range(0,n):
    p = input()
    l = []
    array = raw_input()
    array = array.split()
    for i in array:
        l.append(int(i))
    print maxCourses(l,p)