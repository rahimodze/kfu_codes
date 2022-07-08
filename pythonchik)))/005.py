from math import *
def dummy(x):
    return exp(x) - 1
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
    b00 = a11*a22 - a12*a21
    b11 = a00*a22 - a02*a20
    b22 = a00*a11-a01*a10 # вручную пишу транспонированную матрицу дополнений
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
    a0 = b00 * b0 + b01 * b1 + b02 * b2
    a1 = b10 * b0 + b11 * b1 + b12 * b2
    a2 = b20 * b0 + b21 * b1 + b22 * b2
    print('a0 == %24.18f'%(a0))
    print('a1 == %24.18f'%(a1))
    print('a2 == %24.18f'%(a2))
    return 0
rs(1000, dummy)
         
    
