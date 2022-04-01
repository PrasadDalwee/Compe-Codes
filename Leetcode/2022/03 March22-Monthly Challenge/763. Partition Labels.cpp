//  link:https://leetcode.com/problems/partition-labels/
//  Topic: Map, 2-pointers

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        unordered_map <char, int> m;
        
        for(int i=0; i<s.size(); i++)
            m[s[i]]=i;
        
        
        vector <int> ans;
        int start=0, end=0, size=s.size();
        
        for(int i=0; i<size; i++)
        {
            end=max(end,m[s[i]]);
            
            if(i==end || i==size-1)
            {
                ans.push_back(end-start+1);
                start=end=end+1;
            }
        }
        
        return ans;
    }
};