#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'counterGame' function below.
#
# The function is expected to return a STRING.
# The function accepts LONG_INTEGER n as parameter.
#

def counterGame(n):
    powers=[]
    for i in range(65):
        powers.append(2**i)
    
    def div(n):
        for i in range(len(powers)):
            if powers[i]==n:
                return n/2;
            if powers[i]>n:
                return n-powers[i-1];
    
    while True:
        if(n==1):
            return 'Richard'
        n=div(n)
        if(n==1):
            return 'Louise'
        n=div(n)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        result = counterGame(n)

        fptr.write(result + '\n')

    fptr.close()
