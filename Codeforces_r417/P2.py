def foo(a,b,c):
    lor = 0
    steps = 0
    for i in range(n-1,-1,-1):
        if lor == 0:
            far1count = 0
            for j in range(1,m+1,1):
                if a[i][j] == '1':
                    far1count = j
            if far1count == 0:
                lor = 0
            else:
                steps += far1count
                # print steps
                if far1count > m/2:
                    lor = 1
                    if i != 0:
                        steps += m-far1count+1
                else:
                    lor = 0
                    if i != 0:
                        steps += far1count
            # print steps, lor
        else:
            x = a[i][::-1]
            far1count = 0
            for j in range(1,m+1,1):
                if x[j] == '1':
                    far1count = j
            if far1count == 0:
                lor = 1
            else:
                steps += far1count
                # print steps
                if far1count > m/2:
                    lor = 0
                    if i != 0:
                        steps += m-far1count+1
                else:
                    lor = 1
                    if i != 0:
                        steps += far1count
        if i != 0:
            steps += 1
        # print steps, lor
    print steps
    return
x = raw_input()
arr = map(int,x.split())
n = arr[0]
m = arr[1]
building = []
for i in range(0,n):
    row = raw_input()
    building.append(row)
foo(building,m,n)