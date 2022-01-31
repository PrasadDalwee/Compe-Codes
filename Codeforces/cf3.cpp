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
        double hm,dm,hc,dc,k,w,a,h=hc,att=dc;
        cin>>hc>>dc>>hm>>dm>>k>>w>>a;

        
        for(int i=0;i<k+1;i++)
        {
            h=hc+a*(i), att=dc+w*(k-i);
            if(ceil(hm/att)<=ceil(h/dm))
                break;
        }

        if(ceil(hm/att)<=ceil(h/dm))
        {
            cout<<"YES\n\n";
            n--;
            continue;
        }
        
        cout<<"NO\n\n";
        n--;
    }
}