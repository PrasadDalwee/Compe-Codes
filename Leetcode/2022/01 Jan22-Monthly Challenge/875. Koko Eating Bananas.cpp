//  link:https://leetcode.com/problems/koko-eating-bananas/
//  Topic: Binary Search

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int time(vector<int>& piles, int &k)
        {
            int t=0;
            for(auto&i: piles)
                t+=i/k+(i%k!=0); //ceil()
            return t;
        }
    
        int minEatingSpeed(vector<int>& piles, int h) 
        {
            int start=1;
            int end=*max_element(piles.begin(), piles.end());
            
            while(start<end)
            {
                int mid=(start+end)/2;
                
                if(time(piles,mid)>h)
                    start=mid+1;
                else
                    end=mid;
            }
            
            return end;
        }
};
