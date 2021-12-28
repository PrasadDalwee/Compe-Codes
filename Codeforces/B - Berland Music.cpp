#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t>0)
    {
        int n;
        vector<vector<int>> g,b;
        cin>>n;
        int num=n;
        int arr[n];

        for(int i=0;i<num;i++)
            cin>>arr[i];

        string s; //s[n]
        cin>>s;

        for(int i=0;i<num;i++)
        {
            if(s[i]=='1')
            {
                g.push_back({arr[i],i});
            }
            else
                b.push_back({arr[i],i});
        }

        if(g.size()!=0 && g.size()!=n)
        {
            sort(g.begin(),g.end(),greater <>());
            sort(b.begin(),b.end(),greater <>());

            for(auto x: g)
            {
                arr[x[1]]=n;
                n--;
            }

            for(auto x: b)
            {
                arr[x[1]]=n;
                n--;
            }
        }

        for(int i=0;i<num;i++)
                cout<<arr[i]<<" ";
            cout<<endl;

        t--;
    }
    return 0;
}