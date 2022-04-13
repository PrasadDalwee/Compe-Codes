//  link:https://leetcode.com/problems/game-of-life/
//  Topic: 2D Arrays

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    void gameOfLife(vector<vector<int>>& board) 
    {
        int n[8][2]={{-1,-1}, {-1,0}, {-1,1},
                     {0,-1},          {0,1},
                     {1,-1},  {1,0},  {1,1}}; //8 neighbours
        
        int rmax=board.size(), cmax=board[0].size();
        
        for(int i=0; i<rmax; i++)
        {
            for(int j=0; j<cmax; j++)
            {
                int count= 0;
                
                for(auto &x: n)
                    if(i+x[0]>=0 && i+x[0]<rmax && j+x[1]>=0 && j+x[1]<cmax)
                        count+=abs(board[i+x[0]][j+x[1]]%2);
                //cout<<count<<" ";
                if(board[i][j]==0 && count==3) //only case where 0->1
                    board[i][j]=2;
                
                if(board[i][j]==1 && (count<2 || count>3))  //cases where 1->0
                    board[i][j]=-1;             
            } //cout<<"\n";
        }
        
        for(int i=0; i<rmax; i++)
            for(int j=0; j<cmax; j++)
            {
                board[i][j]>0? board[i][j]=1: board[i][j]=0;
            }
    }
};