//  link:https://leetcode.com/problems/single-number/
//  Topic: XOR, Math, Bit-manipulation

#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
        int singleNumber(vector<int>& nums) 
        {
            int ans=0;
            for(auto&x: nums)
                ans=ans^x;
            return ans;
        }
};