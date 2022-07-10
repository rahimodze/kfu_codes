from math import *
def dum(x): # исследуемая функция
    return log(1+x)
def der(x,h,func):  # вычисление производной методом правосторонней конечной разности
    return (func(x+h) - func(x))/h
def deri(x,h,func): # вычисление производной методом центральной конечной разности
    return(func(x+h)-func(x-h))/(2*h)
def deriv(x,h,func): 
    return 4*deri(x,h,func)/3 - deri(x,2*h,func)/3
def rc(eps,func,h,x): #вычисление производной с оценкой погрешности правилом рунге
    h1 = h
    print("начальный шаг = %24.18f"%(h1))
    h2 = h1/2
    print("начальный половинный шаг = %24.18f"%(h2))
    der1 = deri(x,h1,func)
    der2 = deri(x,h2,func)
    diff = abs(der1 - der2)
    err = diff/3
    print("первая ошибка = %24.18f"%(err))
    while err > eps:
        h1 = h2
        h2 = h1/2
        der1 = deri(x,h1,func)
        der2 = deri(x,h2,func)
        diff = abs(der1 - der2)
        if err < diff/3:
            print("запрошенная точность недостижима")
            print("предельная точность при шаге равном == %24.18f"%(h2*2))
            print("%24.18f - соотвествующее значение производной"%(err))
            return 0
            break
        else:
            err = diff/3
    print("%19.18f - шаг для заданной точности"%(h2))
    print("%19.18f - производная"%(der2))
    print("%19.18f - ошибка"%(err))
    return 0
print("производная для функции (1+x)")
print("введите начальный шаг:")
a = float(input())
print("введите допустимое отклонение:")
b = float(input())
print("введите точку, в которой требуется вычислить производную:")
c = float(input())
rc(b,dum,a,c)
