//  link:https://leetcode.com/problems/simplify-path/
//  Topic: String, Stack

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string simplifyPath(string path) 
    {
        int size=path.size();
        stack <string> dir;
        string loc="";
        
        for(int x=0; x<size; x++)
        {
            if(path[x]=='/' || x==size-1)   
            {
                if(path[x]!='/')
                    loc+=path[x];
                
                if(loc.size()>0)
                {
                    if(loc=="..")       //move back to previous directory
                    {   
                        if(!dir.empty())
                            dir.pop();
                    }
                    else if(loc!=".")   //add sub directory
                        dir.push(loc);
                    loc="";
                }
            }
            
            else
                loc+=path[x];
        }
        
        string ans="";
        while(!dir.empty())
        {
            ans='/'+dir.top()+ans;  //create canonical address
            dir.pop();
        }
        
        return ans.size()>0? ans: "/";
    }
};