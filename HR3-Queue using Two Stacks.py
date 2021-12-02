# Enter your code here. Read input from STDIN. Print output to STDOUT
n=int(input())
l=[]
for i in range(n):
    q=input().split()
    #print(q,len(q))
    
    if q[0]=='2':
        l.pop(0)
    elif q[0]=='3':
        print(l[0])
    else:
        l.append(int(q[1]))
    #print(l,"\n")
