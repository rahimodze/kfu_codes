from math import *
def dum(x):
    return exp(x)
def area(a,b,func,h): # метод центральных прямоугольников
    sum = float(0)
    x = float(a+h/2)
    while x < b:
        sum += func(x)
        x+=h
    return sum*h
def areafor(a,b,func,h):
    n = int(abs(b-a)/h)
    sum = float(0)
    x = float(a+h/2)
    for i in range(n):
        sum += func(x)
        x+=h
        i+=i
    return sum*h
def trapezoid(a,b,func,h): # метод трапеций
    n = int(abs(b-a)/h)
    sum = float((func(a)+func(b))/2)*h
    x = float(a)
    for i in range(n):
        sum += func((x))
        x+=h
        i+=i
    return sum*h - (func(a)+func(b))*h/2
def doublegauss(a,b,func,h): # 2-узловая квадратура Гаусса
    sum = float(0)
    x = float(h/2)
    while x < b:
        sum +=(func(x-h/(2*sqrt(3))) + func(x+h/(2*sqrt(3))))
        x+=h
    return sum*h/2
def parabola(a,b,func,h): # метод Симпсона
    sum = float(0)
    x = float(h/2)
    while x < b:
        sum += (func(x-h/2) + 4*func(x) + func(x+h/2))/6
        x+=h
    return sum*h
def tripleparabola(a,b,func,h): # 3-узловая квадратура Гаусса
    sum = float(0)
    x = float(h/2)
    while x < b:
        sum += (5*func(x-h/(2*sqrt(5/3))) + 8*func(x) + 5*func(x+h/(2*sqrt(5/3))))/18
        x+=h
    return sum*h
print("шаг 0.01")
print("численное\t\t реальное\t\t ошибка\n%19.18f%24.18f%24.18f\t | метод трапеций"%(trapezoid(0,1,dum,0.01),exp(1) - exp(0),trapezoid(0,1,dum,0.01) - exp(1) + exp(0) ))
print("%19.18f%24.18f%24.18f\t | метод центральных прямоугольников с циклом while"%(area(0,1,dum,0.01),exp(1) - exp(0),area(0,1,dum,0.01) - exp(1) + exp(0)))
print("%19.18f%24.18f%24.18f\t | метод центральных прямоугольников с циклом for"%(areafor(0,1,dum,0.01),exp(1) - exp(0),areafor(0,1,dum,0.01) - exp(1) + exp(0)))
print("%19.18f%24.18f%24.18f\t | 2-узловая квадратура Гаусса"%(doublegauss(0,1,dum,0.01),exp(1) - exp(0),doublegauss(0,1,dum,0.01) - exp(1) + exp(0)))
print("%19.18f%24.18f%24.18f\t | метод Симпсона"%(parabola(0,1,dum,0.01),exp(1) - exp(0),parabola(0,1,dum,0.01) - exp(1) + exp(0)))
print("%19.18f%24.18f%24.18f\t | 3-узловая квадратура Гаусса "%(tripleparabola(0,1,dum,0.01),exp(1) - exp(0),tripleparabola(0,1,dum,0.01) - exp(1) + exp(0)))
print("шаг 0.001")
print("численное\t\t реальное\t\t ошибка\n%19.18f%24.18f%24.18f\t | метод трапеций"%(trapezoid(0,1,dum,0.001),exp(1) - exp(0),trapezoid(0,1,dum,0.001) - exp(1) + exp(0) ))
print("%19.18f%24.18f%24.18f\t | метод центральных прямоугольников с циклом while"%(area(0,1,dum,0.001),exp(1) - exp(0),area(0,1,dum,0.001) - exp(1) + exp(0)))
print("%19.18f%24.18f%24.18f\t | метод центральных прямоугольников с циклом for"%(areafor(0,1,dum,0.001),exp(1) - exp(0),areafor(0,1,dum,0.001) - exp(1) + exp(0)))
print("%19.18f%24.18f%24.18f\t | 2-узловая квадратура Гаусса"%(doublegauss(0,1,dum,0.001),exp(1) - exp(0),doublegauss(0,1,dum,0.001) - exp(1) + exp(0)))
print("%19.18f%24.18f%24.18f\t | метод Симпсона"%(parabola(0,1,dum,0.001),exp(1) - exp(0),parabola(0,1,dum,0.001) - exp(1) + exp(0)))
print("%19.18f%24.18f%24.18f\t | 3-узловая квадратура Гаусса "%(tripleparabola(0,1,dum,0.001),exp(1) - exp(0),tripleparabola(0,1,dum,0.001) - exp(1) + exp(0)))
