//  link:https://leetcode.com/problems/sort-array-by-parity/
//  Topic: Two-Pointers

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int odd=0, eve=nums.size()-1;
        while(odd<eve)
        {
            if(nums[odd]%2==1 && nums[eve]%2==0)
                swap(nums[odd],nums[eve]);
            if(nums[odd]%2!=1)
                odd++;
            if(nums[eve]%2!=0)
                eve--;
        }
        
        return nums;
    }
};