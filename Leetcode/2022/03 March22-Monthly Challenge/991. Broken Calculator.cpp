//  link:https://leetcode.com/problems/broken-calculator/
//  Topic: Greedy, Recursion

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brokenCalc(int start, int target) 
    {
        if(start>=target) return start-target;
        
        if(target%2==0) return 1+brokenCalc(start, target/2);
        
        return 1+brokenCalc(start, target+1);
    }
};