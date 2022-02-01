//  link:https://leetcode.com/problems/maximize-distance-to-closest-person/
//  Topic: Arrays, 2-pointer approach

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int maxDistToClosest(vector<int>& seats) 
        {
            int start=0,end=0,maxd=0;

            while(end<seats.size())
            {
                if(seats[end]==0)
                {
                    end++;
                    continue;
                }
                
                if(start==0)
                    maxd=end;
                else
                    maxd=max(maxd, (end-start+1)/2);
                
                end++;
                start=end;
            }

            if(seats[end-1]==0)
                maxd=max(maxd,end-1-start);
            return maxd;
        }
};

int main()
{
    vector<int> v={0,0,0,1,1,0,1,0,0,0,0,0,1,0,0};
    Solution s;
    cout<<s.maxDistToClosest(v);
}