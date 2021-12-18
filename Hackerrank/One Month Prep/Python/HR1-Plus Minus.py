#!/bin/python3

import math
import os
import random
import re
import sys


def plusMinus(arr):
    p=0
    n=0
    z=0
    t=0
    for i in arr:
        if i>0:
            p+=1
        elif i==0:
            z+=1
        else:
            n+=1
        t+=1
        
    if p==t or z==t or n==t:
        print(p/t,"\n",n/t,"\n",z/t)
    else:
        p=float(p)
        t=float(t)
        z=float(z)
        n=float(n)
        print(round(p/t,6),"\n",round(n/t,6),"\n",round(z/t,6))

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
