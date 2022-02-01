//  link:https://leetcode.com/problems/palindrome-partitioning/
//  Topic: Backtracking

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    string s;
    vector<vector<string>> ans;
    vector<string> curr;

    bool check(int i, int j)
    {
        while(i<j)
            if( s[i++]!=s[j--])
                return false;
        
        return true;
    }

    void next(int start)
    {
        if(start>=s.length())
            ans.push_back(curr);

        for(int end=start; end<s.length();end++)
            if(check(start,end))
            {
                curr.push_back(s.substr(start,end-start+1));
                next(end+1);

                curr.pop_back();
            }
    }

    public:
    vector<vector<string>> partition(string s) 
    {
        this->s=s;
        next(0);
        return ans;
    }
};


int main()
{
    Solution s;
    string str;
    cin>>str;
    vector<vector<string>> v=s.partition(str);

    for(auto x:v)
    {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
}