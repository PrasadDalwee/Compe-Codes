//  link: https://leetcode.com/problems/find-all-anagrams-in-a-string/
//  Topic: hash table, string, sliding window

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        void count(string s, vector<int> &freq)
        {
            for(auto &i: s)
                freq[i-'a']++;
            
        }
    
        vector<int> findAnagrams(string s, string p) 
        {
            if(p.size()>s.size())
                return {};
            
            vector<int> freqp(26,0), freqt(26,0), ans;
            count(p,freqp);
            count(s.substr(0,p.size()),freqt);
            if(freqt==freqp)
                ans.push_back(0);
            
            int i=1;
            while(i<=s.size()-p.size())
            {
                freqt[s[i-1]-'a']--;
                freqt[s[i+p.size()-1]-'a']++;
                
                if(freqt==freqp)
                    ans.push_back(i);
                i++;
            }
            
            return ans;
        }
};
