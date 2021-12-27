//  link:https://leetcode.com/problems/number-complement/
//  Topic: Bit manipulation

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int findComplement(int num) 
    {
        int x=0,ans=0;
        while(num)
        {
            if((num&1)==0)
                ans+=1<<x;//left shift 1 x times to get 1+10^x and add to ans 
            
            num>>=1;//right shift num by 1 to remove last bit or LSB
            x++;
        }

        return ans;

    }
};

int main()
{
    int n;
    cout<<"\nEnter no.: ";
    cin>>n;
    Solution s;
    cout<<endl<<"1's complement: "<<s.findComplement(n);
    
}