//  link:https://leetcode.com/problems/design-add-and-search-words-data-structure/submissions/
//  Topic: map, string

#include<bits/stdc++.h>
using namespace std;

class WordDictionary 
{
    unordered_map<int,vector<string>> dic;
    public:
        WordDictionary() 
        {
            
        }
        
        void addWord(string word) 
        {
            if(dic.find(word.size())==dic.end())
                dic[word.size()]={word};
            else
                dic[word.size()].push_back(word);
        }
        
        bool search(string word) 
        {
            if(dic.find(word.size())==dic.end())
                return false;
            
            auto v=dic[word.size()];

            for(auto w: v)
            {
                for(int idx=0;idx<word.size();idx++)
                {
                    if(w[idx]==word[idx] || word[idx]=='.')
                    {
                        if(idx==word.size()-1)
                            return true;
                    }
                    else
                        break;
                }
            }

            return false;
        }
};

int main()
{
    
}