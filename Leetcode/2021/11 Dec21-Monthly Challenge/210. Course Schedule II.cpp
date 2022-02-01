//  link:https://leetcode.com/problems/course-schedule-ii/
//  Topic: Graphs, Topological sort

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& prereq) 
    {
        vector<int> incoming(num,0),ans;
        
        for(auto arr: prereq)
            incoming[arr[0]]++;

        queue<int> q;
        
        for(int i=0;i<incoming.size();i++)
            if(incoming[i]==0)
                q.push(i);
        
        
        while(!q.empty())
        {
            int x=q.front();
            for(auto pre:prereq)
            {
                if(pre[1]==x)
                {
                    incoming[pre[0]]--;

                    if(incoming[pre[0]]==0)
                        q.push(pre[0]);
                }
            }
            
            ans.push_back(x);
            q.pop();
        }
        
        if(ans.size()<num)
            ans.clear();
        return ans;
                    
    }
};