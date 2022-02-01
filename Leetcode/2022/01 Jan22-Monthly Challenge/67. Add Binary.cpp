//  link:https://leetcode.com/problems/add-binary/
//  Topic: 2D Maths, Arrays

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        string addBinary(string a, string b) 
        {
            int i=a.size()-1, j=b.size()-1, carry=0;
            string ans="";

            while(i>=0 || j>=0 || carry>0)
            {
                carry+= (  i>=0? a[i]-'0': 0  ) + (  j>=0? b[j]-'0':0  );
                ans= to_string( carry%2 ) + ans;

                i--; j--;
            }

            return ans;
        }
};


int main()
{
    string s1,s2;
    cin>>s1>>s2;
    Solution c;
    cout<<"\n"<<c.addBinary(s1,s2);
}