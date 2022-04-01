//  link: https://leetcode.com/problems/contiguous-array/
//  Topic: Array, Prefix sum, Hash tables

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int findMaxLength(vector<int>& nums) 
        {
            unordered_map<int,int> match;
            
            int x=-1,sum=0;
            match[0]=-1;
            
            int maxdist=0; 
            
            for(x=0;x<nums.size();x++)
            {
                sum+= nums[x]==0?-1:1; // 0->-1, 1->+1
                
                if(match.find(sum)==match.end())
                    match[sum]=x;
                
                else
                    maxdist=max(maxdist,x-match[sum]);
            }
            
            return maxdist;           
        }
};