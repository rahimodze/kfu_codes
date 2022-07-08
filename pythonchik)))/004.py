from tkinter import *
from math import *
root = Tk() # создание объекта Tkinter
canvas = Canvas(root,width=800,height=700,bg='white',cursor='pencil') #настройки окна
oval = canvas.create_oval(100,100,150,150,outline='green',fill='blue') #тестовая фигура
def func(x): # тестовая функция
    return exp(x)
def move(event): # текущее положение курсора в название окна
    x = event.x
    y = event.y
    s = "Движение мышью {}x{}".format(x, y)
    root.title(s)
root.bind('<Motion>', move)
def keyspace(event): # жми пробел чтоб спустить овальчик)))
    canvas.move(oval,10,10)
def do_zoom(event): # зум и перемещение
    x = canvas.canvasx(event.x)
    y = canvas.canvasy(event.y)
    factor = 1.001 ** event.delta
    canvas.scale(ALL, x, y, factor, factor)
canvas.bind("<MouseWheel>", do_zoom)
canvas.bind('<ButtonPress-1>', lambda event: canvas.scan_mark(event.x, event.y))
canvas.bind("<B1-Motion>", lambda event: canvas.scan_dragto(event.x, event.y, gain=1))
root.bind('<Key-space>',keyspace)
for i in range(7): # создание сетки
    canvas.create_line(100,100*(i+1),700,100*(i+1))
for k in range(8):
    canvas.create_line(100*(k+1),100,100*(k+1),700)
j = float(0)
while j < 628:
    canvas.create_oval(100+j,600 - 100*func(j/100),100+j+1,599-100*func(j/100),outline='black')
    canvas.create_line(100+j,602,100+j,598)
    canvas.create_line(98,600 - 100*func(j/100),102,600 - 100*func(j/100))
    j+=1
canvas.create_text(75,600,text='(0,0)',font='cambria-math 16')
canvas.pack() # перенос на окно холста
root.mainloop() # зацикливание до закрытия
#canvas.create_text(500,500,text='exp',font='cambria-math 56')
 
