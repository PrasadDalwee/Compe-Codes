//  link:https://leetcode.com/problems/can-place-flowers/
//  Topic: 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) 
    {
        bed.insert(bed.begin(),0);
        bed.insert(bed.end(),0);
        
        for(int i=0;i<bed.size();i++)
        {
            if(bed[i]==1) 
                i++;
            
            else if( bed[i-1]==0 and bed[i+1]==0)
            {
                i++;
                n--;
                if(n<1)
                    return 1;
            }
            
        }
                
        return 0;
    }
};

int main()
{
    vector <int> f={1,0,0,0,0,0,0,0,1};
    int n=3;
    Solution S;
    cout<<S.canPlaceFlowers(f,n)<<endl;

    for(auto&i:f)
        cout<<i;

}