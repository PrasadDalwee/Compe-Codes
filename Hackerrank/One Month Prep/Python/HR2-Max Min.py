#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'maxMin' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER k
#  2. INTEGER_ARRAY arr
#

def maxMin(k, arr):
    arr.sort()
    a=len(arr)
    diff=[0]*(a-1)
    w=k-1   #window size
    
    for i in range(0,a-1):  #diff array
        diff[i]=arr[i+1]-arr[i]
    
    window=0
    for i in range(0,w):    
        window+=diff[i]
        
    unfairness=window
    
    for i in range(1,a-w):
        window=window-diff[i-1]+diff[i+w-1]
        if unfairness>window:
            unfairness=window
            
    return unfairness
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    k = int(input().strip())

    arr = []

    for _ in range(n):
        arr_item = int(input().strip())
        arr.append(arr_item)

    result = maxMin(k, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
