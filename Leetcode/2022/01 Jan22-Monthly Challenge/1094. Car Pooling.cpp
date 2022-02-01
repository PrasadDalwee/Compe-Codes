//  link:https://leetcode.com/problems/car-pooling/
//  Topic: Arrays

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        bool carPooling(vector<vector<int>>& trips, int capacity) 
        {
            int track[1001]={0};
            
            for(auto& x: trips)
            {
                track[x[1]]+=x[0];
                track[x[2]]-=x[0];
            }

            int sum=0;
            for(auto& x: track)
            {
                sum+=x;
                if(sum>capacity)
                    return false;
            }
            return true;
        }
};

int main()
{
    cout<<"\nTotal trips:";
    int trip;cin>>trip;

    cout<<"\nCapacity:";
    int cap; cin>>cap;

    cout<<"\nPassenger from  to\n";

    vector<vector<int>> trips;
    for(int i=0;i<trip;i++)
    {
        int t,s,e;
        cin>>t>>s>>e;
        trips.push_back({t,s,e});
    }

    Solution s;
    cout<<endl<<s.carPooling(trips,cap);
}