//  link:
//  Topic: 

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n>0)
    {
        int x;
        cin>>x;

        if(x%7==0)
            cout<<x<<endl;
        
        else
        {
            int d=(x/7)*7;
            if(d/10==x/10)
                cout<<d<<endl;
            else
                cout<<d+7<<endl;
        }

        n--;
    }
}