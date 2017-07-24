import sys
def findMax(a,b,array):
    count = 0
    for i in range(b):
        if(array[i] == 1):
            count += 1
    if a - b == 0:
        # print "Hey"
        print count
        return
    else:
        countref = count
        for i in range(b,a,1):
            if array[i-b] == 1:
                count -= 1
            if array[i] == 1:
                count += 1
            if(count >= countref):
                countref = count

        # print "Hey"
        print countref
        return

def SATreq(a,b,c,list1,req):
    for i in range(c):
        if req[i] == '!':
            a1 = list1.pop()
            list1 = [a1] + list1
            # print list1
        else:
            findMax(a,b,list1)

# tokenizedInput = sys.stdin.read().split()
array = raw_input()
n, k, p = map(int,array.split())
l = []
array = raw_input()
array = array.split()
for i in array:
    l.append(int(i))
request = raw_input()
SATreq(n,k,p,l,request)