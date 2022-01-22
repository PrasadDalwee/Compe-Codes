//  link:https://leetcode.com/problems/stone-game-iv/
//  Topic: Math, DP, greedy

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        bool winnerSquareGame(int n) 
        {
            vector <bool> dp(n+1,false);
            
            for(int i=1; i<=n;i++) //builds dp bottom up i.e 1->n
                for(int j=1;j*j<=i;j++)
                    if(dp[i-j*j]==false) //does bob lose after alice removes j*j
                    {
                        dp[i]=true; //alice wins on i if she removes j*j
                        break;
                    }
            
            return dp[n];
        }
};
