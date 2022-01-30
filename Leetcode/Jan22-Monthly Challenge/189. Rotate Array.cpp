//  link:https://leetcode.com/problems/rotate-array/
//  Topic: Logic, Array

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        void reverse(vector<int>& nums, int i, int j)
        {
            while(i<j)
            {
                int x=nums[i];
                nums[i]=nums[j];
                nums[j]=x;
                
                i++;
                j--;
            }
        }
    
        void rotate(vector<int>& nums, int k) 
        {   
            k=k%nums.size();
            
            reverse(nums, 0, nums.size()-k-1);
            reverse(nums, nums.size()-k,nums.size()-1);
            
            reverse(nums, 0,nums.size()-1);            
        }
};

