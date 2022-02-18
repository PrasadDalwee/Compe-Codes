//  link:
//  Topic: 

#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
        
        string removeKdigits(string num, int k) 
        {
            string ans;
            for(auto &x: num)
            {
                int top=ans.size()-1;

                cout<<" num: "<<num<<" ans: "<<ans<<"  x: "<<x<<endl;

                if(top>-1 && x<ans[top] && k>0)
                {
                    while(top>-1 && x<ans[top] && k>0)
                    {
                        cout<<"\t ans[top]: "<<ans[top]<<" x:"<<x<<endl;
                        ans.pop_back();
                        top--;
                        k--;
                    }
                }

                else
                    ans.push_back(x);
            }
            return ans;
        }
};

int main()
{
    int k=2;
    string num="1020304";
    //cin>>num>>k;
    Solution S;
    cout<<S.removeKdigits(num,k);
}