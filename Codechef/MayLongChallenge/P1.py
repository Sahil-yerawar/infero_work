def logDay(n):
    for i in range(0,n):
        s = raw_input()
        t = ""
        for i in range(0,len(s)):
            if s[i] == "C" :
                t += "0"
            elif s[i] == "E" :
                t += "1"
            else:
                t += "2"
        # print t
        p = 0
        for i in range(0,len(s)-1):
            if(int(t[i]) > int(t[i+1])):
                print "no"
                p = 1
                break
        if(p == 0):
            print "yes"


n = input()
logDay(n)
