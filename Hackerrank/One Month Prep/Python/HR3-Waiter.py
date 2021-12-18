#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'waiter' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY number
#  2. INTEGER q
#
def calc_prime(n):
    i=0
    prime=[]
    num=2
    
    while i<n:
        co=0
        for x in range(2,int(num**0.5)+1):
            if(num%x==0):
                co=1
                break
        if co==0:
            prime.append(num)
            i+=1
        num+=1
        
    return prime

def waiter(number, q):
    prime=calc_prime(q)
    A=number
    answers=[]
    
    print(prime)

    i=0
    while(i<q):
        p=prime[i]
        A1=[]
        for x in range(len(A)):
            if A[x]%p==0:
                answers.append(A[x])
            else:
                A1.append(A[x])
        A1.reverse()
        A=A1
        i+=1
        
    A.reverse()
    for i in A:
        answers.append(i)
    return answers

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    q = int(first_multiple_input[1])

    number = list(map(int, input().rstrip().split()))

    result = waiter(number, q)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
