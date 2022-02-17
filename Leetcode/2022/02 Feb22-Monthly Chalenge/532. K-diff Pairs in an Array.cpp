//  link:https://leetcode.com/problems/k-diff-pairs-in-an-array/
//  Topic: 

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int findPairs(vector<int>& nums, int k) 
        {
            unordered_map<int,int> match;
            int ans=0;
            
            for(auto &x: nums)
                match[x]++;         
            
            if(k==0)
            {
                for(auto &m: match)
                    if(m.second>1)
                        ans++;
            }
            
            else
            {
                for(auto &m: match)
                    if(match.find(m.first + k)!=match.end())
                        ans++;
            }
            
            return ans;
        }
};