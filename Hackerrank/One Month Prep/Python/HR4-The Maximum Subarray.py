#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'maxSubarray' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def maxSubarray(arr):
    # Write your code here
    maxsum=-9999
    possum=0
    currsum=0
    
    for i in arr:
        currsum+=i
        if currsum<0:
            currsum=0
            
        if currsum>maxsum:
            maxsum=currsum
            
        if i>0:
            possum+=i
    
    if maxsum<=0:
        maxsum=-9999
        for i in arr:
            if i>maxsum:
                maxsum=i
        possum=maxsum
    return [maxsum,possum]
            

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        arr = list(map(int, input().rstrip().split()))

        result = maxSubarray(arr)

        fptr.write(' '.join(map(str, result)))
        fptr.write('\n')

    fptr.close()
