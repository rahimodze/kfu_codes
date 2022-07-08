from math import *
def dum(x):
    return exp(x)
def area(a,b,func,n):
    h = float(abs(b-a)/n)
    sum = float(0)
    x = float(a+h/2)
    while x < b:
        sum += func(x)
        x+=h
    return sum*h
#print("%20.18f"%(area(0,1,dum,1000)))
def areafor(a,b,func,n):
    h = float(abs(b-a)/n)
    sum = float(0)
    x = float(a+h/2)
    for i in range(n):
        sum += func(x)
        x+=h
        i+=i
    return sum*h
print("%24.18f%24.18f"%(areafor(0,1,dum,10000),exp(1) - exp(0) ))
def trapezoid(a,b,func,n):
    h = float(abs(b-a)/n)
    sum = float((func(a)+func(b))/2)*h
    x = float(a)
    for i in range(n):
        sum += func((x))
        x+=h
        i+=i
    return sum*h - (func(a)+func(b))*h/2
def doublegauss(a,b,func,n):
    h = float(abs(b-a)/n)
    sum = float(0)
    x = float(h/2)
    while x < b:
        sum +=(func(x-h/(2*sqrt(3))) + func(x+h/(2*sqrt(3))))
        x+=h
    return sum*h/2
def parabola(a,b,func,n):
    h = float(abs(b-a)/n)
    sum = float(0)
    x = float(h/2)
    while x < b:
        sum += (func(x-h/2) + 4*func(x) + func(x+h/2))/6
        x+=h
    return sum*h
def tripleparabola(a,b,func,n):
    h = float(abs(b-a)/n)
    sum = float(0)
    x = float(h/2)
    while x < b:
        sum += (5*func(x-h/(2*sqrt(5/3))) + 8*func(x) + 5*func(x+h/(2*sqrt(5/3))))/18
        x+=h
    return sum*h
print("%24.18f%24.18f%24.18f"%(trapezoid(0,1,dum,100),exp(1) - exp(0),trapezoid(0,1,dum,100) - exp(1) + exp(0) ))
print("%24.18f%24.18f%24.18f"%(doublegauss(0,1,dum,100),exp(1) - exp(0),doublegauss(0,1,dum,100) - exp(1) + exp(0)))
print("%24.18f%24.18f%24.18f"%(parabola(0,1,dum,100),exp(1) - exp(0),parabola(0,1,dum,100) - exp(1) + exp(0)))
print("%24.18f%24.18f%24.18f"%(tripleparabola(0,1,dum,100),exp(1) - exp(0),tripleparabola(0,1,dum,100) - exp(1) + exp(0)))
