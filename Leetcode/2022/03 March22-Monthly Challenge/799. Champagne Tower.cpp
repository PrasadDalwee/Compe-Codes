//  link:https://leetcode.com/problems/champagne-tower/
//  Topic: Dynamic Programming

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) 
    {
        vector<double> curr(query_row+1,0), next(query_row+1,0), clear(query_row+1,0);
        curr[0]=(double) poured;    //flow of first glass
        for(int i=1; i<=query_row; i++)
        {
            for(int j=0; j<i; j++)
                next[j]+=next[j+1]+= max( (curr[j]-1)/2, 0.0);  //pour into next rows if flow>1
            curr=next;  next=clear; //shift rows
        }
        return min( 1.0, curr[query_glass]);    //flow>=1 => glass is full
    }
};