//  link:https://leetcode.com/problems/counting-bits/
//  Topic: bits, binary numbers, maths, pattern finding

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) 
    {
        if(n==0) return {0};
        int x=1;
        vector <int> ans(n+1);
        ans[0]=0;
        while(x<=n)
        {
            ans[x]=1;
            x=2*x;
        }
        
        x=2;
        int base;
        while(x<=n)
        {
            if(ans[x]==1)
                base=x;
            else
                ans[x]=1+ans[x-base];
            x++;
        }
        
        return ans;
    }
};