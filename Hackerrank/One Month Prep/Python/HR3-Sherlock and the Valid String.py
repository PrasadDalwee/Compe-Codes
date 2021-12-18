#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'isValid' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def isValid(s):
    if len(s)<2:
        return "YES";
    
    d={}
    for i in s:
        if i in d.keys():
            d[i]+=1
        else:
            d[i]=1
    print(d)
    
    v={}
    for i in d.values():
        if i in v.keys():
            v[i]+=1
        else:
            v[i]=1
    v=dict(sorted(v.items()))
    print(v)
    if len(v)<3:
        if len(v)==1:
            return "YES"
        
        if 1 in v.keys():
            if v[1]==1:
                return "YES"
        
        k=list(v.keys())
        print(k,v[k[1]],v[k[0]])
        
        if k[1]-k[0]==1 and v[k[1]]==1:
            return "YES"
            
    
    return "NO"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = isValid(s)

    fptr.write(result + '\n')

    fptr.close()
