# Enter your code here. Read input from STDIN. Print output to STDOUT
Q=int(input())
S=''
Sp=[]
while Q>0:
    C=input().split()
    c=int(C[0])
    
    
    if c==1:
        W=C[1]
        Sp.append(S)
        S=S+W
        
    elif c==2:
        k=int(C[1])
        Sp.append(S)
        S=S[:-k]
    
    elif c==3:
        k=int(C[1])
        print(S[k-1])
    
    else:
        S=Sp.pop()
    
    Q-=1
