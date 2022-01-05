//  link:https://leetcode.com/problems/burst-balloons/
//  Topic: 2D Arrays, Dynamic Programming.

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:

        int maxCoins(vector<int>& nums)
        {
            int size=nums.size();

            nums.insert(nums.begin(),1);
            nums.insert(nums.end(),1);

            int val[size+2][size+2];

            for(int i=1; i<=size; i++)
                val[i][i]=nums[i-1]*nums[i]*nums[i+1];

            for(int steps=1; steps<size; steps++)
            {
                for(int i=1; i<=size-steps; i++)
                {
                    int maxx=-1;

                    for(int j=i; j<=i+steps; j++) // j marks last ele to pop
                    {
                        int sum= nums[i-1]*nums[j]*nums[i+steps+1];
                        if(j>i)
                            sum+=val[i][j-1];
                        if(j<i+steps)
                            sum+=val[j+1][i+steps];

                        maxx=max(sum,maxx);
                    }

                    val[i][i+steps]=maxx;
                }
            }


            return val[1][size];
        }

        
};

int main()
{
    
    int n,x; cout<<"\nn: ";cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        cin>>x; 
        nums.push_back(x);
    }
    
    Solution s;
    cout<<"\n\nANS:"<<s.maxCoins(nums);
    return 0;
}