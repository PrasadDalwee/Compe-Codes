//  link:https://leetcode.com/problems/complement-of-base-10-integer/submissions/
//  Topic: Bit manipulation

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) 
    {
        if(n==0 || n==1)
            return 1^n;

        int x=1;
        while(x<n)
            x=2*x;        
        x=x-1;
        return x^n;
    }
};

int main()
{
    int n;
    cout<<"\nEnter no.: ";
    cin>>n;
    Solution s;
    cout<<endl<<"1's complement: "<<s.bitwiseComplement(n);
    
}