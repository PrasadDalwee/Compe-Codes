//  link:https://leetcode.com/problems/sequential-digits/submissions/   
//  Topic: 

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:

        vector<int> sequentialDigits(int low, int high) 
        {
            vector<int> ans;
            int digit=floor(log10(low)+1);
            
            int num=0;
            for(int i=1;i<=digit;i++)
                num=num*10+i;
            
            
            int num1=num;
            
            int add=0;
            for(int i=1;i<=digit;i++)
                add=10*add+1;
            
            while(num<=high)
            {
                if(num>=low)
                    ans.push_back(num);
                if(num%10==9)
                {
                    digit++;
                    num=10*num1+num1%10+1;
                    num1=num;
                    add=10*add+1;
                }
                else
                    num=num+add;
            }
            return ans;
        }
};

