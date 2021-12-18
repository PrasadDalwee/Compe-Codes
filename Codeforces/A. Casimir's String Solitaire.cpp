#include <iostream>
#include<string>
using namespace std;
 
int main()
{
    int t;
    int a,b,c;
    string s;
    cin>>t;
    while(t>0)
    {
        a=0;b=0;c=0;
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='A') a++;
            if(s[i]=='B') b++;
            if(s[i]=='C') c++;
        }
        if(b==a+c) cout<<"YES\n";
        else cout<<"NO\n";
        t--;
    }
 
    return 0;
}
