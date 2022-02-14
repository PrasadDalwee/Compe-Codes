//link:https://codeforces.com/contest/1637/problem/A

#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n;
        cin>>n;
        vector <int> v(n), prefix(n-1), suffix(n-1);
        for(int i=0;i<n;i++)
            cin>>v[i];

        prefix[0]=v[0];
        suffix[n-2]=v[n-1];

        for(int i=1; i<n-1; i++)
        {
            prefix[i]=max(prefix[i-1],v[i]);
            suffix[n-2-i]=min(suffix[n-1-i],v[n-1-i]);
        }

        int check=1;
        for(int i=0; i<n-1; i++)
        {
            if(suffix[i]<prefix[i])
            {
                check=0;
                cout<<"YES\n";
                break;
            }
        }
        if(check)
            cout<<"NO\n";

        t--;
    }
}