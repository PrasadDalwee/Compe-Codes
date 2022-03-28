//  link:https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
//  Topic: Set, Sort, Arrays

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector <int> ans;
        
        set<pair<int,int>> army;
        
        for(int i=0;i<mat.size(); i++)
        {
            int cnt=count(mat[i].begin(), mat[i].end(), 1);
            army.insert({cnt,i});
        }
        
        for(auto x= army.begin(); x!=army.end() , k>0; x++, k--)
            ans.push_back(x->second);
        
        return ans;
    }
};