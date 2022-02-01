//  link:https://leetcode.com/problems/basic-calculator-ii/
//  Topic: Maths( for optimization), stacks(for initial intuition)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) 
    {
        s+="+";                                 //makes sure that last operations get added to ans
        int curr=0,last=0,len=s.length(),ans=0;
        char lastsign='+';
        
        for(int i=0;i<len;i++)
        {
            //cout<<" s[i]: "<<s[i]<<" curr="<<curr<<" last="<<last<<" ans:"<<ans<<" lastsign:"<<lastsign<<endl;

            if(isdigit(s[i]))
            {
                curr=curr*10+(s[i]-'0');
            }
            
            else if(!iswspace(s[i]))            //testcases have whitespaces
            {
                if(lastsign=='-')
                        curr=curr*(-1);
                
                if(lastsign=='*' || lastsign=='/')
                {
                    if(lastsign=='*')
                        curr=last*curr;
                    else
                        curr=last/curr;
                }
                
                if(s[i]=='+' || s[i]=='-')
                {
                    ans+=curr;
                }
                
                else if(s[i]=='/' || s[i]=='*')
                {
                    last=curr;
                }
                
                 curr=0;
                 lastsign=s[i];
            }
        }
        
        return ans;
    }
};

int main()
{
    Solution S;
    cout<<"\nEnter:";
    string s;
    cin>>s;
    cout<<"\n\nAns="<<S.calculate(s);
    return 0;
}