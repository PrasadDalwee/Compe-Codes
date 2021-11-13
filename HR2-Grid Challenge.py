#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'gridChallenge' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING_ARRAY grid as parameter.
#

def gridChallenge(grid):
    check=0
    
    for i in range(len(grid)):
        grid[i]=sorted(grid[i])
    
    col=['x']*len(grid)
    
    for y in range(len(grid[0])):
        for x in range(len(grid)):
            col[x]=grid[x][y]
        print(col,'\n',sorted(col))
        if(col==sorted(col)):
            check+=1
    
    if(check==len(grid[0])):
        return 'YES'    
    return 'NO'
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        grid = []

        for _ in range(n):
            grid_item = input()
            grid.append(grid_item)

        result = gridChallenge(grid)

        fptr.write(result + '\n')

    fptr.close()
