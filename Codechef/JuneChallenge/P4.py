def allOnes(n):
    return ((n+1) & n == 0) and (n!=0)
def ore(a,b,k):
    for i in range(0,k):
        if a[i] != '1' and b[i] != '1':
            return False
    return True

_end = '_end_'
def make_trie(a):
    root = dict()
    # t = Trie()
    for i in a:
        current_dict = root
        for j in i:
            current_dict = current_dict.setdefault(j, {})
        current_dict[_end] = _end
    return root
def check_other(p,a):
    # p = x
    o = ""
    # print p
    for i in a:
        if i == '0':
            if '1' in p:
                o += '1'
                p = p['1']
                # print p
            else:
                return False
        elif i == '1':
            if '1' in p:
                o += '1'
                p = p['1']
                # print p
            elif '0' in p:
                o += '0'
                p = p['0']
                # print p
            else:
                return False
    else:
        if _end in p:
            return True
        else:
            return False
    return False

def foo(a,b,c):
    count = 0
    k = b
    max_sum = (k*(k+1))/2
    l = []
    for i in xrange(0,len(a)-1):
        l.append(max_sum-c[i])
    mina = min(c)
    maxa = max(c)
    for i in xrange(0,len(a)-1):
        # print i
        o = l[i]
        if(o == 0):
            count += len(a)-1-i
            continue
        elif(maxa<o):
            continue
        # u = [p for p in a if p < o]
        # # print u
        # if len(u)<=1:
        # flag =1
        else:
            for j in xrange(i+1,len(a)):
                if c[j] >= o:
                    if ore(a[i],a[j],k):
                        count += 1
    return count
def foo1(a,b):
    count = 0
    x = make_trie(a)
    # print x.get_all()
    for i in a:
        if check_other(x,i):
            count += 1
    return count

t = input()
for i in xrange(0,t):
    x = raw_input()
    x = map(int,x.split())
    n = x[0]
    k = x[1]
    counts = []
    sums = []
    for j in xrange(0,n):
        p = raw_input()
        p = map(int,p.split())
        size = p[0]
        p = p[1:]
        u = ['0']*k
        # al = '1'*k
        # print p
        x=0
        for f in xrange(0,size):
                u[p[f]-1] = '1'
                x +=p[f]
        # print ''.join(n)
        sums.append(x)
        counts.append(''.join(u))
    # print sums
    # print counts
    print foo1(counts,k)