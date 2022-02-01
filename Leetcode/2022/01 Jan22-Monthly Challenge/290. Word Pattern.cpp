//  link:https://leetcode.com/problems/word-pattern/
//  Topic: Arrays, 2-pointer approach

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        bool wordPattern(string pattern, string s) 
        {
            unordered_map<char,string> match;
            unordered_map<string,char> check;
            
            stringstream sentence(s);
            string word;
            int l=0;
            while(sentence>>word)
            {
                if(l>=pattern.size()) //underflow
                    return 0;

                if(match.find(pattern[l])==match.end()) //char not found
                {
                    if(check.find(word)!=check.end())   //word found in map
                        return 0;
                    
                    match[pattern[l]]=word;
                    check[word]=pattern[l];
                }

                if(match[pattern[l]]!=word)    //mismatch
                    return 0;
    
                l++;
            }

            if(l<pattern.size())    //overflow
                return 0;

            return 1;
        }
};

int main()
{
    string s="as you sow so you reap";
    string pattern="ef";
    Solution S;
    cout<<S.wordPattern(pattern,s);
}