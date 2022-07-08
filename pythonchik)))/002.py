from math import *
def dum(x):
    return log(1+x)
def der(x,h,func):
    return (func(x+h) - func(x))/h
def deri(x,h,func):
    return(func(x+h)-func(x-h))/(2*h)
def deriv(x,h,func):
    return 4*deri(x,h,func)/3 - deri(x,2*h,func)/3
def rc(eps,func,h,x):
    h1 = h
    print("first step = %24.18f"%(h1))
    h2 = h1/2
    print("first half step = %24.18f"%(h2))
    der1 = deriv(x,h1,func)
    der2 = deriv(x,h2,func)
    diff = abs(der1 - der2)
    err = diff/15
    print("first error = %24.18f"%(err))
    while err > eps:
        h1 = h2
        print("step = %24.18f"%(h1))
        h2 = h1/2
        print("half step = %24.18f"%(h2))
        der1 = deriv(x,h1,func)
        der2 = deriv(x,h2,func)
        diff = abs(der1 - der2)
        print("error = %24.18f"%(diff))
        if err < diff/15:
            print("destinated accuracy cannot be achieved")
            print("maximum accuracy with h equal == %24.18f"%(h2))
            print("%24.18f - it's derivative"%(der2))
            return 0
            break
        else:
            err = diff/15
    print("%24.18f - step for this accuracy"%(h2))
    print("%24.18f - first derivative"%(der2))
    print("%24.18f - error"%(err))
    return 0
'''
print("derivative for log (1+x)")
print("enter initial step:")
a = float(input())
print("enter epsilon:")
b = float(input())
print("enter needed point:")
c = float(input())
rc(b,dum,a,c)
'''
def area(a,b,func,n):
    h = float(abs(b-a)/n)
    sum = float(0)
    i = int(0)
    x = a
    while i < n:
        x +=(i+1)*h/2
        sum = sum + func(x)*h
        print("%f"%(0.5*(i+1)*h))
        i = i + 1
    return sum
print("%20.18f"%(area(0,1,dum,1000)))
