//  link:https://leetcode.com/problems/jump-game-iv/
//  Topic: Arrays

#include<bits/stdc++.h>
using namespace std;

void print(queue<int> q,vector<int>& arr)
{
    while(!q.empty())
    {
        cout<<q.front()<<"("<<(q.front()>-1?arr[q.front()]:0)<<")"<<" ";
        q.pop();
    }
    cout<<endl;
}

class Solution 
{
    public:
        int minJumps(vector<int>& arr) 
        {
            if(arr.size()<2)                                // no jumps required for 0 or 1 total elements
                return 0;

            if(arr[0]==arr[arr.size()-1])                   //no need to waste space if first and last elements are equal, jump always=1
                return 1;

            unordered_map<int,vector<int>> idx;             //map to track array indixes with equal values
            for(int i=0;i<arr.size();i++)
                idx[arr[i]].push_back(i);

            vector <bool> unvisited(arr.size(),1);          //array to mark visited nodes

            int step=1, end=arr.size()-1;        

            queue<int> q;                                   //queue to maintain sequence of next possible jump indixes
            q.push(0);

            while(!q.empty())
            {
               int size=q.size();
               //print(q,arr);

               for(int i=0;i<size;i++)                          //traverse elements pushed into queue 
               {
                   int top=q.front();
                   q.pop();

                   if(idx.find(arr[top])!=idx.end())            //jump to index of equal value if key exists
                   {
                       for(auto& j:idx[arr[top]])
                       {
                           if(j==end)
                            return step;

                            if(j!=top)
                                q.push(j);
                            unvisited[j]=0;
                       }

                       idx.erase(arr[top]);                      //erase map entry
                   }

                   if(top-1>=0 && unvisited[top-1])             //jump previous
                   {
                       q.push(top-1);
                       unvisited[top-1]=0;
                   }

                   if(top+1<arr.size() && unvisited[top+1])     //jump next
                   {
                        if(top+1==end)
                            return step;
                        q.push(top+1);
                        unvisited[top+1]=0;
                   }
               }

                step++;                 
            }

            return step-1;
        }
};

int main()
{

    vector <int> v ={100,-23,-23,404,100,23,23,23,3,404};
   
    Solution s;
    cout<<s.minJumps(v);
}