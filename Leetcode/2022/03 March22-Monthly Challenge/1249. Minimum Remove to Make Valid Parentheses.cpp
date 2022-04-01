//  link:https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
//  Topic: String, prefix-suffix counters

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string minRemoveToMakeValid(string ans) 
    {
        int size=ans.size(), open=0, close=0;
        for(int i=0; i<size; i++)
        {
            if(ans[i] =='(')
                open++;
            else if(ans[i] ==')')
            {
                open>0? open--: ans[i]='#';
            }
        }
        
        for(int i=size-1; i>-1; i--)
        {
            if(ans[i] ==')')
                close++;
            else if(ans[i] =='(')
            {
                close>0? close--: ans[i]='#';
            }
        }
        
        ans.erase(remove(ans.begin(), ans.end(), '#'), ans.end());
        
        return ans;
    }
};