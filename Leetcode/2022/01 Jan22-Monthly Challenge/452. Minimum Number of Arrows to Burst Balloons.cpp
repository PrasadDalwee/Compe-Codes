//  link:https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
//  Topic: Greedy, Array, 2D columnwise sorting

#include<bits/stdc++.h>
using namespace std;

bool sortcol(const vector<int> &v1, const vector<int> &v2)    //ascending col based sort
{
    return v1[1]<v2[1];
}

class Solution 
{   
    public:
        int findMinArrowShots(vector<vector<int>>& points) 
        {
            sort(points.begin(),points.end(),sortcol);
            int arrow=1, flag=points[0][1];

            for(auto &i: points)
            {
                if(i[0]>flag)
                {
                    arrow++;
                    flag=i[1];
                }
            }

            return arrow;
        }
};

int main()
{
    int n;
    cout<<"n:";
    cin>>n;
    vector<vector<int>> v(n,vector<int> (2));
    for(int i=0;i<n;i++)
        cin>>v[i][0]>>v[i][1];
    
    Solution s;
    cout<<endl<<s.findMinArrowShots(v);
}