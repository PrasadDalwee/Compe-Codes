//link:https://codeforces.com/contest/1690/problem/A

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
        int a=n/3 -1;
        int b=(n+1)/3;
        int c=n-a-b;
        cout<<b<<" "<<a<<" "<<c<<endl;
        t--;
    }
}