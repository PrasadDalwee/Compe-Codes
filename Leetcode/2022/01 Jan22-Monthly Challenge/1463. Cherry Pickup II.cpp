//  link:https://leetcode.com/problems/cherry-pickup-ii/solution/
//  Topic: Dynamic Programming

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int cherryPickup(vector<vector<int>>& grid) 
        {
            int m=grid.size();
            int n=grid[0].size();

            vector<vector<vector <int>>> dp(m,vector<vector<int>> (n, vector<int> (n,0)));

            dp[0][0][n - 1] = 0 == n - 1 ? grid[0][0] : grid[0][0] + grid[0][n - 1];

            for(int row=1; row<m; row++)
            {
                for(int c1=0; c1<min(n,row+1); c1++)
                {
                    for(int c2=max(0,n-1-row); c2<n; c2++)
                    {
                        int previous_max=0;

                        for(int robo1= max(0,c1-1); robo1<= min(n-1,c1+1); robo1++)
                        {
                            for(int robo2=max(0,c2-1); robo2<=min(n-1,c2+1); robo2++)
                            {
                                previous_max=max(previous_max, dp[row-1][robo1][robo2]);
                            }
                        }

                        if(c1==c2)
                            dp[row][c1][c2]=previous_max+grid[row][c1];
                        else
                            dp[row][c1][c2]=previous_max+grid[row][c1]+grid[row][c2];
                    }
                }
            }

            int res=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0; j<n;j++)
                {
                    res=max(res,dp[m-1][i][j]);
                }
            }

            return res;
            
        }
};


int main()
{
    int row,col;
    cout<<"\n Enter no. of rows and columns: ";
    cin>>row>>col;

    vector<vector<int>> grid;
    for(int i=0; i<row; i++)
    {
        grid.push_back({});
        for(int j=0;j<col;j++)
        {
            int ip;cin>>ip;
            grid[i].push_back(ip);
        }
    }

    Solution s;
    cout<<s.cherryPickup(grid);

}