//  link:https://leetcode.com/problems/is-subsequence/
//  Topic: Stack, String

#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        bool isSubsequence(string s, string t) 
        {        
            for(int x=t.size()-1; x>=0 && !s.empty(); x--)
                if (t[x]==s[s.size()-1]) s.pop_back();   //treating subsequence string as a stack
            return s.empty();
        }
};