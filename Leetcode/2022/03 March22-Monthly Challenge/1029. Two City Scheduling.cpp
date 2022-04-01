//  link:https://leetcode.com/problems/two-city-scheduling/
//  Topic: Greedy, Array, Sorting

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        int a=0,b=0,sum=0;
        vector <int> diff;
        
        for(auto &x: costs)
        {
            sum+=x[0];
            diff.push_back(x[1]-x[0]);
        }
        
        sort(diff.begin(), diff.end());
        
        for(int i=0; i<diff.size()/2; i++)
            sum+=diff[i];
        
        return sum;
    }
};