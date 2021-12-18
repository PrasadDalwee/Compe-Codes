#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'climbingLeaderboard' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY ranked
#  2. INTEGER_ARRAY player
#

def climbingLeaderboard(ranked, player):
    # Write your code here
    leaders=[9999999999]
    prev=ranked[0]
    leaders.append(prev)
    for i in ranked:
        if prev!=i:
            leaders.append(i)
            prev=i
    print(player,leaders)
    ans=[]
    i=len(leaders)-1
    j=0
    
    while j<len(player):
        if leaders[i]>player[j]:
            j+=1
            ans.append(i+1)
        elif leaders[i]==player[j]:
            j+=1
            ans.append(i)
        elif leaders[i]<player[j]:
            i-=1
    return ans
            
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ranked_count = int(input().strip())

    ranked = list(map(int, input().rstrip().split()))

    player_count = int(input().strip())

    player = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(ranked, player)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
