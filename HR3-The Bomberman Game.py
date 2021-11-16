#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'bomberMan' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts following parameters:
#  1. INTEGER n
#  2. STRING_ARRAY grid
#

def bomberMan(n, grid):
    def replac(s,i,x):
        return s[:i]+x+s[i+1:]
        
    def boom(x):
        dot='.'
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==x:
                    grid[i]=replac(grid[i],j,dot)
                    if i>0 and  grid[i-1][j]!=x:
                        grid[i-1]=replac(grid[i-1],j,dot)
                        
                    if j>0 and  grid[i][j-1]!=x:
                        grid[i]=replac(grid[i],j-1,dot)
                        
                    if i<len(grid)-1 and  grid[i+1][j]!=x:
                        grid[i+1]=replac(grid[i+1],j,dot)
                        
                    if j<len(grid[0])-1 and  grid[i][j+1]!=x:
                        grid[i]=replac(grid[i],j+1,dot)

    def place(x):
        for i in range(len(grid)):
            grid[i]=grid[i].replace('.',x)
    
    def show():
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] not in ['O','.']:
                    grid[i]=replac(grid[i],j,'O')
    # def printf():
    #     for i in grid:
    #         print(i)
            
    if(n==1):
        return grid
    if(n==2):
        place('1')
        show()
        return grid
    n=n%4
    i=3    
    x='O'
    # printf()
    # print("\n")
    place('1')
    while i<=n+4:
        
        if i%2==0:
            place(x)
            if x=='O':
                x='1'
            else:
                x='O'
        else:
            boom(x)
        i+=1
        # printf()
        # print("\n")
    show()
    return grid
            
            
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    r = int(first_multiple_input[0])

    c = int(first_multiple_input[1])

    n = int(first_multiple_input[2])

    grid = []

    for _ in range(r):
        grid_item = input()
        grid.append(grid_item)

    result = bomberMan(n, grid)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
