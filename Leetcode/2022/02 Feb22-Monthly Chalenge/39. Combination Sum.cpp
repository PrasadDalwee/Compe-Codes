//  link:https://leetcode.com/problems/combination-sum/
//  Topic: Recursion, Backtracking

#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
        vector<vector<int>> ans;
        vector<int> nums;
        
        void permute(vector<int> combination, int target, int sum, int loc)
        {
            if(target==sum)
            {   ans.push_back(combination); return; } //add combination to answer if target reached
            
            for(int i=loc; i<nums.size();i++) //iterate to generate combination
            {
                int x=nums[i];
                if(sum+x>target)    //because canidates are sorted in ascending order 
                    return;
                combination.push_back(x);
                permute(combination,target,sum+x,i);
                combination.pop_back();
            }
        }
    
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
        {
            sort(candidates.begin(),candidates.end());  //sort helps in better iterations
            nums=candidates;
            permute({},target,0,0);
            return ans;
        }
};