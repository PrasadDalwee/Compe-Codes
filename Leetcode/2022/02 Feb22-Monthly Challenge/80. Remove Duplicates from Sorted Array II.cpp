//  link:https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
//  Topic: Array

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int removeDuplicates(vector<int>& nums) 
        {
            if(nums.size()<3)
                return nums.size();
            
            int copy=1, i=nums.size()-2, k=1;
            
            for(i; i>-1; i--)
            {
                if(nums[i]==nums[i+1])
                {
                    copy++;
                    if(copy>2)
                    {
                        nums.erase(nums.begin()+i);
                        continue;
                    }
                    
                }
                
                else
                    copy=1;
                
                k++;
            }
            
            return k;
        }
};