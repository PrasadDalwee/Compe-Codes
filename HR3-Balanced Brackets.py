#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'isBalanced' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def isBalanced(s):
    # Write your code here
    pairs={'{':'}','[':']','(':')'}
    openers=pairs.keys()
    stack=[]
    
    for i in s:
        if  i in openers:
            stack.append(i)
        elif len(stack)==0:         #most important step, else RTE will occur
            return 'NO'
        elif i!=pairs[stack.pop()]:
                return 'NO'
    
    return 'NO' if stack else 'YES'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        s = input()

        result = isBalanced(s)

        fptr.write(result + '\n')

    fptr.close()
