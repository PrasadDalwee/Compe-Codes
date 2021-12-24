//  link:https://leetcode.com/problems/merge-intervals/
//  Topic: 2D arrays, Sorting

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> ans;
        
        int max=intervals[0][1];
        int last=max;
        int first=intervals[0][0];
        
        for(auto p: intervals)
        {
            if(p[0]<=max)
            {
                if(max<p[1])
                    max=p[1];
                last=max;
            }
            
            else
            {
                vector <int> inter={first,last};
                ans.push_back(inter);
                first=p[0];
                last=p[1];
                max=p[1];
            }
        }
        
        vector <int> inter={first,last};
        ans.push_back(inter);
        
        return ans;
        
    }
};