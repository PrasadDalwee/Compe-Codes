#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    hour=s[0:2]
    mins=s[3:5]
    sec=s[6:8]
    zone=s[8:]
    
    if zone=='AM':
        if hour=='12':
            hour='00'
    else:
        if hour!="12":
            hr=int(hour)
            hr+=12
            hour=str(hr)
    return hour+':'+mins+':'+sec

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
