//  link:https://leetcode.com/problems/remove-k-digits/submissions/
//  Topic: Stack, String

#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:  
        string removeKdigits(string num, int k) 
        {
            string ans; //string stack
            
            for(auto &x: num)
            {
                int top=ans.size()-1;
                while(top>-1 && x<ans[top] && k>0)  //pop the top of stack if x<top
                { ans.pop_back();   top--;  k--; }
                
                ans.push_back(x);
            }
            
            while(k>0)  //pop top if k>0
            { ans.pop_back(); k--; }
            
            int i;
            for(i=0;i<ans.size();i++)//remove leading zeroes
                if(ans[i]!='0') break;
            ans= ans.substr(i); 
            
            return ans=="" ? "0": ans;  //empty string=> 0
        }
};