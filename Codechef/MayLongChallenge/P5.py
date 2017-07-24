import copy
def foo1(a,b,c):
    rej_pre = []
    if not b:
        print -1
        return
    elif not a:
        for i in b:
            rej_pre.append(i[0])
        rej_pre.sort()
        s = []
        for i in rej_pre:
            if i not in s:
                s.append(i)
        print len(s)
        for i in s:
            print i
        return
    else:
        # print b.sort()
        d = sorted(b)
        # print d
        b.append('!')
        b = ['!'] + b
        for i in list(d):
            if i in b:
                for j in range(0,len(i)):
                    if b[b.index(i)+1].startswith(i):
                        x = b[b.index(i)+1]
                        b.remove(x)
                        c.remove(x)
                        break

        # print b
        b.remove('!')
        b.remove('!')
        c.sort()
        # print c
        c.append('!')
        c = ['!'] + c
        for i in b:
            t = c.index(i)
            # leftl = 0,leftb = 0,rightl = 0, rightb = 0
            left = c[t-1]
            right = c[t+1]
            p = 0
            while p != len(i):
                if left.startswith(i[0:p+1]):
                    p += 1
                else:
                    break
            q = 0
            while q != len(i):
                if right.startswith(i[0:q+1]):
                    q += 1
                else:
                    break
            if q == len(i) and right in acc_s:
                print -1
                return
            list1 = [p]+[q]
            maxi = max(list1)
            rej_pre.append(i[0:maxi+1])
        rej_pre.sort()
        s = []
        for i in list(rej_pre):
            if i in rej_pre:
                if rej_pre.index(i) != len(rej_pre)-1:
                    if  i[0] == rej_pre[rej_pre.index(i)+1][0]:
                        s.append(i[0])
                        rej_pre.remove(rej_pre[rej_pre.index(i)+1])
                    else:
                        s.append(i)
                else:
                    s.append(i)

        # for i in list(rej_pre):
        #     rej_pre.remove()
        #     for
        print len(s)
        for i in s:
            print i
        return
def foo(a,b):
    rej_pre = []
    if not b:
        print -1
        return
    elif not a:
        for i in b:
            rej_pre.append(i[0])
    else:
        dummy = copy.deepcopy(a)
        # print dummy
        for i in b:
            for j in range(0,len(i)):
                # print dummy
                for k in list(dummy):
                    if not k.startswith(i[0:j+1]):
                        dummy.remove(k)
                    # print dummy, j
                    if not dummy:
                        break
                if j == len(i)-1 and dummy:
                    print -1
                    return
                elif not dummy:
                    rej_pre.append(i[0:j+1])
                    dummy = copy.deepcopy(a)
                    # print dummy
                    break

    rej_pre.sort()
    s = []
    for i in rej_pre:
        if i not in s:
            s.append(i)
    print len(s)
    for i in s:
        print i
    return

# t = "codeforces_v2"
# print t.startswith("codeforces")
n = input()
acc_s = []
rej_s = []
web_s = []
for i in range(0,n):
    array = raw_input()
    array = array.split()
    web_s.append(array[1])
    if array[0] == '+':
        acc_s.append(array[1])
    else:
        rej_s.append(array[1])
foo1(acc_s, rej_s, web_s)
