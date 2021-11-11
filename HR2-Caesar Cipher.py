#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'caesarCipher' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING s
#  2. INTEGER k
#

def caesarCipher(s, k):
    # Write your code here
    s1=''
    for i in s:
        x=ord(i)
        a=ord('a')
        A=ord('A')
        
        if x>=a and x<=a+25:
            if x+k>a+25:
                x=a+(x+k-a-26)
            else:
                x+=k
            s1+=chr(x)
            
        elif x>=A and x<=A+25:
            if x+k>A+25:
                x=A+(x+k-A-26)
            else:
                x+=k
            s1+=chr(x)
            
        else:
            s1+=i
    return s1

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = input()

    k = int(input().strip())

    result = caesarCipher(s, k)

    fptr.write(result + '\n')

    fptr.close()
