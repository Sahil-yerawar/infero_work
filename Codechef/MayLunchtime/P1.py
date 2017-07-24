def foo(s):
	n = len(s)
	flag = 0
	count = 0
	for i in range(n-1,-1,-1):
		if flag != int(s[i]):
			flag = 1 -flag
			count += 1
			print str(i)+" "+str(flag)
		
	return count

s = raw_input()
print foo(s)
			
