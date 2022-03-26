//  link:https://leetcode.com/problems/binary-search/
//  Topic: Binary Search

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int start=0, end=nums.size()-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            
            if(target==nums[mid])
                return mid;
            
            if(target>nums[mid])
                start=mid+1;
            
            else
                end=mid-1;
        }
        return -1;
    }
};