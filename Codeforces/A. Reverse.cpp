//link:https://codeforces.com/contest/1638/problem/A

#include<bits/stdc++.h>
using namespace std;

// void print(vector<int> &v)
// {
//     for(auto &x: v)
//         cout<<x<<" ";
//     cout<<"\n";
// }

int main ()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n;
        cin>>n;

        vector <int> v(n);
        int j=0,k=0;
        for(int i=0; i<n;i++)
            cin>>v[i];
        
        for(int i=0;i<n;i++)
        {   
             if(v[i]!=i+1)
             {
                 j=i;
                 break;
             }
        }
        
        for(int i=j+1;i<n;i++)
        {   
             if(v[i]==j+1)
              {  
                  k=i;
                  break;
              }
        }

        //cout<<j<<k<<endl;
        reverse((v.begin()+j), (v.begin()+k+1));
        
        for(auto &x: v)
            cout<<x<<" ";
        cout<<"\n";
        t--;
    }
}