def foo(a,b,c,d):
    times = []
    for i in range(0,a):
        times.append((abs(c[i]-b))/speedarr[i])
    x = sorted(times)
    if(x[0] == x[1]):
        print -1
        return
    else:
        print times.index(x[0])
        return


x = raw_input()
arr = map(int,x.strip().split())
n = arr[0]
x = arr[1]
pos = raw_input()
posarr = map(int,pos.strip().split())
speeds = raw_input()
speedarr = map(int,speeds.strip().split())
foo(n,x,posarr,speedarr)