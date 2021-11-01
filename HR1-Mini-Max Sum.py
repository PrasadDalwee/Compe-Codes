#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'miniMaxSum' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def miniMaxSum(arr):
    # Write your code here
    arr1=sorted(arr)
    min=0
    max=0
    for i in range(0,4):
        min+=arr1[i]
    for i in range(1,5):
        max+=arr1[i]
    print(min,max)
    # print(arr1)
if __name__ == '__main__':

    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
