#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t>0)
    {
        int a,b,c;
        cin>>a>>b>>c;

        int sum=a+b+c;
        int max1=max(a,max(b,c));
        if (max1==sum-max1)
         cout<<"YES\n";
        else
        {
            if((a==b && c%2==0)||(b==c && a%2==0)||(c==a && b%2==0))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }

        t--;
    }
    return 0;
}