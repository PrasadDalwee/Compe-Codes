//link:https://codeforces.com/contest/1690/problem/D

#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        int st=0,e=0,b=0,w=0,ans;

        for(e=0; e<k; e++)
        {
            s[e]=='B'? b++ : w++;
            ans=w;
        }
        for(;e<n;e++)
        {
            s[st]=='B'?b--:w--;
            s[e]=='B'?b++:w++;
            st++;
            ans=min(w,ans);
        }

        cout<<ans<<endl;
        t--;
    }
}