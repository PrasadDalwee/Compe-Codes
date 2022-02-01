//link: https://leetcode.com/problems/k-closest-points-to-origin/
//topics: basic maths(for brute force solution), min heap,etc.(for optimization)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
       vector<vector<int>> dist;
       int y,x,d,z=0; 
       for(auto i: points)
       {
           x=i[0];
           y=i[1];
           d=x*x + y*y;
           dist.push_back({d,z});
           //cout<<d<<endl;
           z++;
       }

       sort(dist.begin(),dist.end());

       vector<vector<int>> ans;

       for(int i=0;i<k;i++)
       {
           ans.push_back(points[dist[i][1]]);
       }

       return ans;
    }
};

int main()
{
    cout<<"\nEnter total no. of points: ";
    int n,k;
    cin>>n;

    vector<vector<int>> points;

    cout<<"\nEnter points: \n";
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        points.push_back({x,y});
    }

    cout<<"\nEnter K: "; cin>>k;
    
    Solution s;
    vector<vector<int>> ans=s.kClosest(points,k);

    cout<<"\n\nK closest points from origin are: \n";
    for(int i=0;i<k;i++)
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
}