x = '#'
n = int(input())
z = n-2
y = 0
for i in range(n,1,-1) :
    if i == n :
        print(x * n + '\n')
    elif i == 2 :
        print(" " * (n//2) + x + '\n')
    else :
        print( y * " " + x + " " * z + x + '\n')
        z = z-2
        y = y+1
z = 1
y = 1
for i in range(3,n+1) :
    if i == n :
        print(x * n + '\n')
    else :
        print( y * " " + x + " " * z + x + '\n')
        z = z+2
        y = y-1
            
        