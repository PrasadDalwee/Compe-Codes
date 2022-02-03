//  link:https://leetcode.com/problems/4sum-ii/
//  Topic: Arrays, Hash Table

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        unordered_map <int,int> m1;
 
        
        for(auto &x: nums1)
            for(auto &y: nums2)
                m1[x+y]++;
        
        int ans=0;
        
        for(auto &x: nums3)
            for(auto &y: nums4)
                ans+=m1[-(x+y)];
        
        return ans;
    }
};