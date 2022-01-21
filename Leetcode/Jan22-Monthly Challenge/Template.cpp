//  link:
//  Topic: 

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        bool travel(vector<int>& gas, int &start)
        {
            int sum=0, end=-1;
            
            if(gas[start]<=0)
                return 0;
            
            cout<<start<<endl;

            end=start;
            sum+=gas[end];
            cout<<"\t"<<end<<" "<<sum<<endl;
            end=(end+1)%gas.size();

            while(end!=start)
            {
                sum+=gas[end];
                cout<<"\t"<<end<<" "<<sum<<endl;
                end=(end+1)%gas.size();
                if(sum<0)
                    return 0;
            }
            return 1;
        }
    
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
        {
            int sum=0;
            for(int i=0;i<gas.size();i++)
            {    
                gas[i]-=cost[i];
                sum+=gas[i];
            }
            cout<<endl<<sum<<endl;
            

            if(sum<0)
                return -1;
            
            for(int start=0;start<gas.size();start++)
                if(travel(gas,start))
                    return start;
            
            return -1;
            
        }
};

int main()
{
    vector<int> gas, cost;
    gas={2};
    cost={2};
    Solution S;
    cout<<S.canCompleteCircuit(gas,cost);
}