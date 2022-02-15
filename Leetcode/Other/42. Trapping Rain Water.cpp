//  link:https://leetcode.com/problems/trapping-rain-water/
//  Topic: 2-pointers, DP, Array

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int trap(vector<int>& height) 
        {
            int n=height.size(), ans=0;
            
            vector<int> left(n);
            vector<int> right(n);
            
            left[0]=height[0];
            right[n-1]=height[n-1];
            
            for(int i=1;i<n;i++)
            {
                left[i]= max(left[i-1],height[i]);
                right[n-1-i]= max(right[n-i], height[n-1-i]);
            }
            
            for(int i=0;i<n;i++)
                ans+=min(left[i],right[i])-height[i];
            
            return ans;
        }
};