#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int smallestRepunitDivByK(int k) 
        {
            if(k%2==0 || k%10==5)
                return -1;
            
            int rem=0;


            for(int n=1;n<=k;n++)   //no. of diff. remainders can be atmost k(0->k-1)
            {   
                rem=(rem*10 +1)%k;
                if(rem==0)        
                    return n;
            }

            return -1;            
        }
};

int main()
{
    Solution s;
    cout<<s.smallestRepunitDivByK(5);
}