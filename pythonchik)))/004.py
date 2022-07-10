from tkinter import *
from math import *
root = Tk() # создание объекта Tkinter
canvas = Canvas(root,width=800,height=700,bg='white',cursor='pencil') #настройки окна
def func(x): # тестовая функция
    return exp(x)
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
    canvas.create_oval(100+j,600 - 100*func(j/100),100+j+1,599-100*func(j/100),outline='blue')
    canvas.create_line(100+j,602,100+j,598)
    canvas.create_line(98,600 - 100*func(j/100),102,600 - 100*func(j/100))
    j+=1
canvas.create_text(75,600,text='O',font='cambria-math 14')
canvas.create_text(725,620,text='x',font='cambria-math 14')
canvas.create_text(75,100,text='y',font='cambria-math 14')
canvas.create_text(75,500,text='1',font='cambria-math 14')
canvas.create_text(200,450,text='f(x) = exp(x)',font='cambria-math 14')
canvas.create_text(200,610,text='1',font='cambria-math 14')
canvas.pack() # перенос на окно холста
root.mainloop() # зацикливание до закрытия
 
