//  link:https://leetcode.com/problems/richest-customer-wealth/
//  Topic: Arrays, matrix

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int maxw=0;
        for(auto &x: accounts)
        {
            int sum=0;
            for(auto &i: x)
                sum+=i;
            if(sum>maxw)
                maxw=sum;
        }
        
        return maxw;
    }
};
