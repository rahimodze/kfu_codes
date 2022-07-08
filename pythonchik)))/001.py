from math import *
h = 0.1
x = 0.2
i=1
f = log( x + 1 )
re= 1/1.2
print (re)
while i < 20:
    h=0.1**i
    f1 = log( 1 + x + h)
    f2 = log(1 + x - h)
    der = (f1-f2) / (2*h)
    #print (der)
    print("%24.18f%24.18f"%(der,i))
    i= i + 1
#z = func(200,1)
#print ("%24.18f"%(z))


