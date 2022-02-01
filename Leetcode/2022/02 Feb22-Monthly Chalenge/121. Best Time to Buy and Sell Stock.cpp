//  link:https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//  Topic: 

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int maxProfit(vector<int>& prices) 
        {
            int sell=0, buy=prices[0];
            for(int i=1;i<prices.size(); i++)
            {
                if(prices[i]<=buy)
                    buy=prices[i];
                else
                {
                    if(prices[i]-buy>sell)
                        sell=prices[i]-buy;
                }
            }
            return sell;
        }
};

