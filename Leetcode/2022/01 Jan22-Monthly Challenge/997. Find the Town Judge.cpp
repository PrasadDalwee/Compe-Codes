//  link:https://leetcode.com/problems/find-the-town-judge/
//  Topic: Arrays/Hash Table

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {       
         vector<int> suspects (n+1,0);  //we dont need two arrays as we want that trustee=n-1 and trusted=0 for our judge 0+n-1=n-1

        for(auto &i: trust)
        {
            suspects[i[1]]++;
            suspects[i[0]]--;
        }

        for(int i=1;i<=n;i++)
        {
            if(suspects[i]==n-1)
                return i;
        }
        
        return -1;
    }
};

int main()
{
    cout<<"n:";
    int n;
    cin>>n;

    cout<<"\nLength of array:";
    int len;
    cin>>len;

    vector <vector <int>> trust;

    for(int i=0;i<len;i++)
    {
        int x,y;
        cin>>x>>y;
        trust.push_back({x,y});
    }

    Solution s;
    cout<<s.findJudge(n,trust);
}