//  link:https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
//  Topic: String, Greedy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) 
    {
        string ans(n,'a');
        int sum=n;
        
        for(int i=n-1; i>-1; i--)
        {
            if(sum==k)
                return ans;
            
            else if(k-sum<25)
            {
                ans[i]=ans[i]+k-sum; 
                return ans;
            }   
            
            else
            {
                ans[i]='z';
                sum+=25;
            }
            
        }
        return ans;
    }
};