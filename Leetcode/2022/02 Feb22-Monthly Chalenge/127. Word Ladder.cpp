//  link:https://leetcode.com/problems/word-ladder/
//  Topic: Graph, BFS, String

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        string dest;
    
        int match(unordered_set<string> &s, queue<string> &q)//creates and compares all possible transformations
        {
            string word=q.front();
            for(int i=0; i<word.size();i++)
            {
                string dup=word;
                for(int j=0; j<26; j++)
                {
                    dup[i]='a'+j;
                    if(dup==dest)
                        return 1;
                    if(s.find(dup)!=s.end())
                    {
                        s.erase(s.find(dup));
                        q.push(dup);
                    }
                    //cout<<dup<<endl;
                }
            }
            
            return 0;
        }
        
        
    
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
        {
            unordered_set<string> s;
            queue<string> q;
            
            dest=endWord;
            
            int end_absent=1;
            for(auto& x: wordList)//fill set
            {
                s.insert(x);
                if(x==endWord)
                    end_absent=0;
            }
            
            if(end_absent) //destination not in list 
                return 0;
            
            q.push(beginWord);
            if(s.find(beginWord)!=s.end()) 
                s.erase(s.find(beginWord)); //remove begin word if present

            int depth=0;
            while(!q.empty())
            {
                int nodes= q.size();
                depth++;
                while(nodes!=0)
                {
                    if(match(s,q))
                        return depth+1;
                    q.pop();
                    nodes--;
                }
            }
            
            return 0;
            
        }
};