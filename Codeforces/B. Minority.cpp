//  link:https://codeforces.com/contest/1633/problem/B
//  Topic: 

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n>0)
    {
        string x;
        cin>>x;

        if(x.size()<=2)
        {
            cout<<0<<endl;
            n--;
            continue;
        }

        int a=0,b=0;
        for(auto& i: x)
        {    if(i=='1')
                b++;
            else
                a++;
        }

        if(a<b)
            cout<<a<<endl;
        else if(a>b)
            cout<<b<<endl;
        else if(b==a)
            cout<<b-1<<endl;

        n--;
    }
}
/*

5
1
01
101
1100
11100110

*/