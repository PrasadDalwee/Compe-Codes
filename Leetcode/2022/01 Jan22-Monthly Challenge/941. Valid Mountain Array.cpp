//  link:https://leetcode.com/problems/valid-mountain-array/
//  Topic: Array

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        bool validMountainArray(vector<int>& arr) 
        {
            
            int l=0, e=arr.size()-1;
            if(e<2)
                return false;
        
            for(int i=0;i<e;i++)
                if(arr[i]>=arr[i+1])
                {
                    l=i;
                    break;
                }   
            
            for(int i=e;i>0;i--)
                if(arr[i]>=arr[i-1])
                {
                    e=i;
                    break;
                }
            return l==e;
        }
};

