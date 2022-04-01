//  link:https://leetcode.com/problems/permutation-in-string/
//  Topic: Hashtables, Sliding window

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        
        bool checkInclusion(string s1, string s2) 
        {
            if(s1.size()>s2.size()) //edge case
                return false;
            
            vector<int> og(26,0);  //frequency count of s1
            vector<int> dup(26,0); //frequency count of s2

            for(auto &x: s1)
                og[x-'a']++;
            
            int n=s1.size();        // n elements =size of s1
            for(int i=0; i<n; i++)  //loading first n elements of s2
                dup[s2[i]-'a']++;

            if(dup==og)
                return true;
            
            for(int i=1; i<=s2.size()-n; i++)   //sliding window
            {
                dup[s2[i-1]-'a']--;
                dup[s2[i+n-1]-'a']++;
                if(dup==og)
                    return true;
            }
            
            return false;
        }
};