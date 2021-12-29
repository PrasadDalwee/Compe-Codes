#include <bits/stdc++.h>
using namespace std;
 
 int main()
 {
     int t;
     cin>>t;

     while(t>0)
     {
        int n,m, rb, cb, rd, cd;
        int dr=1,dc=1,time=0;
        cin>>n>>m>>rb>>cb>>rd>>cd;

        if(rb==rd || cb==cd)
            cout<<0<<endl;
        
        else if(cb<cd)
        {
            if(rd>rb)
                cout<<min(cd-cb,rd-rb)<<endl;
            else
                cout<<min(cd-cb,2*(n-rb)+rb-rd)<<endl;
        }

        else if(cd<cb)
        {
            if(rd>rb)
                cout<<min(2*(m-cb)+cb-cd,rd-rb)<<endl;
            else
                cout<<min(2*(m-cb)+cb-cd,2*(n-rb)+rb-rd)<<endl;
        }

         t--;
     }
 }
