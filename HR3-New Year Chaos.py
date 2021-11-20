#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'minimumBribes' function below.
#
# The function accepts INTEGER_ARRAY q as parameter.
#

def minimumBribes(q):
    # Write your code here
    def move(j,x):
        if x==1:
            temp=q[j]
            q[j]=q[j-1]
            q[j-1]=temp
            
        else:
            temp=q[j]
            temp1=q[j-1]
            q[j]=q[j-2]
            q[j-2]=temp1
            q[j-1]=temp
    
    
    q.insert(0,0)
    j=len(q)-1
    bribes=0
    while j>0:
        if(j==q[j]):
            bribes+=0
        elif j==q[j-1]:
            bribes+=1
            move(j,1)
        elif j==q[j-2]:
            bribes+=2
            move(j,2)
        else:
            print('Too chaotic')
            return
        j=j-1
    print(bribes)
    
    

if __name__ == '__main__':
    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)
