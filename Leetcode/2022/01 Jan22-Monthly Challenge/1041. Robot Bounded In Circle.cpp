//  link:https://leetcode.com/problems/robot-bounded-in-circle/
//  Topic: 2D Maths, Arrays

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    int arr[4][2]={ {0,1}, {1,0}, {0,-1}, {-1,0} };          //co-ordinate of right turns i.e. clockwise rotation (N->E->S->W)
    int pos=0;

    public:

        bool isRobotBounded(string &instructions) 
        {
            int x1,y1;
            x1=y1=0;

            move(instructions,x1,y1);
            
            return (x1==0 and y1==0)||pos!=0;           //check if robo has already reached origin 
                                                        //because it will always reach orgin if final direction is not North
        }

        void move(string &instructions, int &x, int &y)
        {
            for( auto& i: instructions)
            {
                if(i=='G')                              //move robo in current direction
                {
                    x+=arr[pos][0];
                    y+=arr[pos][1];
                }

                else if(i=='L')
                    pos=(4+pos-1)%4;                    //anti-clockwise i.e. left turns
                
                else if(i=='R')
                    pos=(pos+1)%4;                      //clockwise i.e right turns
            }
        }
};   

int main()
{
    string s;
    cin>>s;
    Solution S;
    // S.test();
    cout<<S.isRobotBounded(s);
}