//  link:https://leetcode.com/problems/string-to-integer-atoi/
//  Topic: Knowledge of INT_MAX and INT_MIN

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int myAtoi(string s) 
        {
            int num=0, i=0, op=1;
            
            while(s[i]==' ')
                i++;

            if(s[i]=='-')
            {    
                op=-1;
                i++;
            }
            else if(s[i]=='+')
                i++;
            
            while(isdigit(s[i]))
            {
                num=num*10+(s[i]-'0');
                
                if(num>=INT_MAX/10 && isdigit(s[i+1]))
                {
                    if(op==1)
                    {
                        if(isdigit(s[i+2]) || num>INT_MAX/10)
                            return INT_MAX;
                        
                        return (s[i+1]-'0') < 8 ? INT_MAX-7+(s[i+1]-'0'): INT_MAX;
                    }
                    
                    else
                    {    if(isdigit(s[i+2]) || num>INT_MAX/10)
                            return INT_MIN;
                     
                        return (s[i+1]-'0') <= 8 ? INT_MIN+8-(s[i+1]-'0'): INT_MIN;
                    }
                }
                
                i++;
            }
            return num*op;
        }
};

int main()
{
    // string s="  -43+  34 dff";
    // Solution S;
    // cout<<S.myAtoi(s);

    cout<<INT_MIN<<" "<<INT_MIN/10<<" "<<INT_MIN%10;
}