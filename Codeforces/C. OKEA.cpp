//link: https://codeforces.com/contest/1634/problem/C

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
        if(k==1)
        {
            cout<<"YES\n";
            for(int i=1; i<=n; i++)
                cout<<i<<endl;
        }

        else if(n%2==0)
        {
            int x=1;
            cout<<"YES\n";
            
            for(int i=1; i<=n; i+=2)
            {
                int e=x+1;
                for( int j=1; j<=k; j++, x+=2)
                    cout<<x<<" ";

                cout<<endl;
                x=e;

                for( int j=1; j<=k; j++, x+=2)
                    cout<<x<<" ";

                cout<<endl;
                x=x-1;
            }
        }

        else 
            cout<<"NO\n";

        t--;
    }
}