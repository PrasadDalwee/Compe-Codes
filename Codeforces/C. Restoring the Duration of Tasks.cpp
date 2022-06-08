//link:https://codeforces.com/contest/1690/problem/C

#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n; cin>>n;
        vector<int> v1(n),v2(n);
        for(auto&x: v1)
        {   int y; cin>>y; x=y;}
        for(auto&x: v2)
        {   int y; cin>>y; x=y;}
        int curr=0;
        for(int i=0; i<n; i++)
        {
            curr=max(curr,v1[i]);
            cout<<v2[i]-v1[i]<<" ";
        }
        cout<<endl;
        t--;
    }
}