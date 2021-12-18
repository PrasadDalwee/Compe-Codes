#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'equalStacks' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY h1
#  2. INTEGER_ARRAY h2
#  3. INTEGER_ARRAY h3
#

def equalStacks(h1, h2, h3):
    def fillsum(h):
        for i in range(len(h)-1,0,-1):
            h[i-1]+=h[i]
        return h
    
    h1,h2,h3=fillsum(h1),fillsum(h2),fillsum(h3)
    
    x,y,z=0,0,0
    print(h1,h2,h3)
    while True:
        maxsum=min(h1[x],h2[y],h3[z])
        print(x,y,z,maxsum)
        while h1[x]>maxsum:
            x+=1
            if x==len(h1):
                return 0
        while h2[y]>maxsum:
            y+=1
            if y==len(h2):
                return 0
        while h3[z]>maxsum:
            z+=1
            if z==len(h3):
                return 0
        
        if h1[x]==h2[y] and h2[y]==h3[z]:
            return h1[x]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n1 = int(first_multiple_input[0])

    n2 = int(first_multiple_input[1])

    n3 = int(first_multiple_input[2])

    h1 = list(map(int, input().rstrip().split()))

    h2 = list(map(int, input().rstrip().split()))

    h3 = list(map(int, input().rstrip().split()))

    result = equalStacks(h1, h2, h3)

    fptr.write(str(result) + '\n')

    fptr.close()
