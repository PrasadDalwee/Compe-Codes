//  link:https://leetcode.com/problems/detect-capital/
//  Topic: String

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        bool detectCapitalUse(string word) 
        {
            int caps=0;
            for(auto& i: word)
                if(i>='A' && i<='Z')
                    caps++;
            
            if(caps==word.size() || caps==0 || (caps==1 && 'A'<=word[0] && 'Z'>=word[0]))
                return true;
            
            return false;
        }
};

