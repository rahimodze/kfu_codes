from math import *
from tkinter import *
# аппроксимация функции полиномом 2 степени методом наименьших квадратов
def dummy(x):
    return exp(x) - 1
def approx(x,h,o,p):
    return h*x**2 + o*x + p
def rs(N,func):
    phi0=[1]*100
    phi1 = [i/(N-1) for i in range(N)]
    phi2 = [(i/(N-1))**2 for i in range(N)]
    f = [func(phi1[i]) for i in range(N)]
    b0 = float(0)
    b1 = float(0)
    b2 = float(0)
    for i in range(100):
        b0+=float(f[i])*float(phi0[i])/N
        b1+=float(f[i])*float(phi1[i])/N
        b2+=float(f[i])*float(phi2[i])/N
    a00 = float(0)
    a01 = float(0)
    a02 = float(0)
    a10 = float(0)
    a11 = float(0)
    a12 = float(0)
    a20 = float(0)
    a21 = float(0)
    a22 = float(0)
    for i in range(100):
        a00+= float(phi0[i]) * float(phi0[i])/N
        a01+= float(phi0[i]) * float(phi1[i])/N
        a02+= float(phi0[i]) * float(phi2[i])/N
        a10+= float(phi0[i]) * float(phi1[i])/N
        a11+= float(phi1[i]) * float(phi1[i])/N
        a12+= float(phi1[i]) * float(phi2[i])/N
        a20+= float(phi0[i]) * float(phi2[i])/N
        a21+= float(phi1[i]) * float(phi2[i])/N
        a22+= float(phi2[i]) * float(phi2[i])/N
    #ручное задание элементов матрциы
    b00 = a11*a22 - a12*a21
    b11 = a00*a22 - a02*a20
    b22 = a00*a11-a01*a10
    b01 = a02*a21-a01*a22
    b02 = a01*a12-a20*a11
    b10 = a12*a20-a10*a22
    b12 = a02*a10-a00*a12
    b20 = a10*a21-a11*a20
    b21 = a01*a20-a21*a00
    det = a00*a11*a22 + a01*a12*a20 + a02*a10*a21 - a02*a11*a20 - a01*a10*a22 - a00*a12*a21
    b00 = b00/det
    b01 = b01/det
    b02 = b02/det
    b10 = b10/det
    b11 = b11/det
    b12 = b12/det
    b20 = b20/det
    b21 = b21/det
    b22 = b22/det
    a0 = b00 * b0 + b01 * b1 + b02 * b2 # свободный член
    a1 = b10 * b0 + b11 * b1 + b12 * b2 # коэффициент при x
    a2 = b20 * b0 + b21 * b1 + b22 * b2 # коэффициент при x^2
    print('a0 == %24.18f'%(a0))
    print('a1 == %24.18f'%(a1))
    print('a2 == %24.18f'%(a2))
    return a0,a1,a2
a0,a1,a2=rs(1000, dummy)
root = Tk()
canvas = Canvas(root,width=800,height=700,bg='white',cursor='pencil')
def move(event): # текущее положение курсора в название окна
    x = event.x
    y = event.y
    s = "Положение мыши {}x{}".format(x, y)
    root.title(s)
root.bind('<Motion>', move)
def do_zoom(event): # зум и перемещение
    x = canvas.canvasx(event.x)
    y = canvas.canvasy(event.y)
    factor = 1.001 ** event.delta
    canvas.scale(ALL, x, y, factor, factor)
canvas.bind("<MouseWheel>", do_zoom)
canvas.bind('<ButtonPress-1>', lambda event: canvas.scan_mark(event.x, event.y))
canvas.bind("<B1-Motion>", lambda event: canvas.scan_dragto(event.x, event.y, gain=1))
for i in range(6): # создание сетки по y
    canvas.create_line(100,100*(i+1),700,100*(i+1))
for k in range(7): # создание сетки по x
    canvas.create_line(100*(k+1),100,100*(k+1),600)
j = float(0)
while j < 100:
    t = j/100
    canvas.create_oval(100+j,600 - 100*dummy(t),100+j+1,599-100*dummy(t),outline='blue')
    canvas.create_oval(100+j,600 - 100*approx(t,a2,a1,a0),100+j+1,599-100*approx(t,a2,a1,a0),outline='red')
    canvas.create_line(100+j,602,100+j,598)
    canvas.create_line(98,600 - 100*dummy(t),102,600 - 100*dummy(t))
    j+=1
canvas.create_text(75,600,text='O',font='cambria-math 14')
canvas.create_text(725,620,text='x',font='cambria-math 14')
canvas.create_text(75,100,text='y',font='cambria-math 14')
canvas.create_text(75,500,text='1',font='cambria-math 14')
canvas.create_line(650,38,670,38,fill='blue')
canvas.create_text(730,38,text='точное значение',font='cambria-math 8')
canvas.create_line(650,58,670,58,fill='red')
canvas.create_text(730,58,text='аппроксимация',font='cambria-math 8')
canvas.create_text(200,610,text='1',font='cambria-math 14')
canvas.create_line(630,25,790,25,fill='black')
canvas.create_line(790,25,790,75,fill='black')
canvas.create_line(790,75,630,75,fill='black')
canvas.create_line(630,75,630,25,fill='black')
canvas.pack() # перенос на окно холста
root.mainloop() # зацикливание до закрытия
    
