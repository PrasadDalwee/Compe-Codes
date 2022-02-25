//link:https://codeforces.com/contest/1635/problem/B

#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &v)
{
    for(auto&x:v)
        cout<<x<<" ";
    cout<<endl;
}

int main ()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n; cin>>n; 
        vector <int> v;
        int lmax=-1,rmax=-1;
        for(int i=0;i<n;i++)
        {
            int x; cin>>x; v.push_back(x);
            lmax=max(lmax,x);
        }

        int ans=0;
        for(int i=1; i<n-1; i++)
        {
            if(v[i]>v[i-1] && v[i]>v[i+1])
            {
                if(i+2<n)
                {
                    v[i+1]=max(v[i],v[i+2]); 
                }
                else
                    v[i+1]=v[i];
                ans++;
            }
        }
        cout<<ans<<endl;
        print(v);
        t--;
    }
}