//  link:https://leetcode.com/problems/arithmetic-slices/
//  Topic: Array, Dp

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        if(nums.size()<3) return 0;
        
        int diff=nums[1]-nums[0], sub_slices=0, ans=0; 
        
        for(int i=2; i<nums.size(); i++)
        {
            diff==nums[i]-nums[i-1]? sub_slices++: sub_slices=0, diff=nums[i]-nums[i-1];
            ans+=sub_slices;
        }
        
        return ans;
    }
};