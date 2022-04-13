//  link:https://leetcode.com/problems/spiral-matrix-ii/
//  Topic: 2D array

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> v(n, vector <int> (n,0));
        
        int i=1, cmin=0, cmax=n-1, rmax=n-1, rmin=0;
        
        while(rmin<=rmax && cmin<=cmax)
        {
            for(int x=cmin; x<=cmax; x++, i++)
                v[rmin][x]=i;
            rmin++;
            
            for(int x=rmin; x<=rmax; x++, i++)
                v[x][cmax]=i;
            cmax--;
            
            for(int x=cmax; x>=cmin; x--, i++)
                v[rmax][x]=i;
            rmax--;
            
            for(int x=rmax; x>=rmin; x--, i++)
                v[x][cmin]=i;
            cmin++;
        }
        
        return v;
    }
};

