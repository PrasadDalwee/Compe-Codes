//link:https://codeforces.com/contest/1690/problem/B

#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n,flag=1;
        cin>>n;
        vector<int> v1(n), v2(n);
        for(auto&x: v1)
        {   int y; cin>>y; x=y;}
        for(auto&x: v2)
        {   int y; cin>>y; x=y;}

        int zdiff=-1, prevdiff=-1;

        for(int i=0; i<n; i++)
        {
            int d=v1[i]-v2[i];
            
            if(v2[i]==0)
            {
                zdiff=max(zdiff,d);
            }

            else
            {
                if(prevdiff==-1) prevdiff=d;
                else if(prevdiff!=d)
                {
                    flag=0; break;
                }
            }
        }

        if(flag && (zdiff<prevdiff))
            cout<<"YES\n";
        else
            cout<<"NO\n";

        t--;
    }
}