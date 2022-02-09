//link:
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
        string s,s1;
        cin>>s;
        s1=s;
        reverse(s1.begin(), s1.end());
        if(k==0)
            cout<<1<<endl;
        else if(s==s1)
            cout<<1<<endl;
        else
            cout<<2<<endl;
        t--;
    }
}