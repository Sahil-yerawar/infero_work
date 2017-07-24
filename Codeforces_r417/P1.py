def foo(a):
    for i in range(0,4):
        for j in range(0,3):
            if a[i][j] == a[i][3] and a[i][3] == 1:
                print "YES"
                return
        if(i == 0):
            if((a[i+1][0] == a[i][3] or a[i+2][1] == a[i][3]) or a[i+3][2] == a[i][3]) and a[i][3] == 1:
                print "YES"
                return
        elif(i == 1):
            if((a[i+1][0] == a[i][3] or a[i+2][1] == a[i][3]) or a[0][2] == a[i][3]) and a[i][3] == 1:
                print "YES"
                return
        elif(i == 2):
            if((a[i+1][0] == a[i][3] or a[0][1] == a[i][3]) or a[1][2] == a[i][3]) and a[i][3] == 1:
                print "YES"
                return
        elif(i == 3):
            if((a[0][0] == a[i][3] or a[1][1] == a[i][3]) or a[2][2] == a[i][3]) and a[i][3] == 1:
                print "YES"
                return
    print "NO"
    return

junction = []
for i in range(0,4):
    x = raw_input()
    arr = map(int,x.split())
    junction.append(arr)
foo(junction)