x = raw_input()
hour = int(x[0:2])
mina  = int(x[3:5])
y  =x[0:2]
z = x[0]
z = x[1]+z
if mina <= int(z):
    print int(z)-mina
else:
    if(hour != 23):
        if(len(str(hour+1))==1):
            hour1 = "0"+str(hour+1)
        else:
            hour1 = str(hour+1)
    else:
        hour1 = "00"
    if(hour1 == "00"):
        min1 = 60
    else:
        z = hour1[0]
        z = hour1[1] + z
        min1 = 60 + int(z)
    print min1-mina