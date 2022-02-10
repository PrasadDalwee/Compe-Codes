//  link:https://leetcode.com/problems/subarray-sum-equals-k/solution/
//  Topic: Prefixsum, hashmap

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int subarraySum(vector<int>& nums, int k) 
        {
            int count=0, sum=0;
            
            for(int i=0;i<nums.size();i++)
            {
                for(int j=i;j<nums.size();j++)
                {
                    sum+=nums[j];
                    if(sum==k)
                        count++;
                } 
                sum=0;
            }
            
            return count;
            
        }
};