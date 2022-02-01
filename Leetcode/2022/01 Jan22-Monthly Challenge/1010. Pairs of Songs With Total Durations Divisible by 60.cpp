//  link:https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
//  Topic: Arrays, Remainders

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        int arr[60]={0};

        for(int i=0;i<time.size();i++)
            arr[time[i]%60]++;

        int pairs= arr[0]*(arr[0]-1)/2  + arr[30]*(arr[30]-1)/2;

        for(int i=1;i<30;i++)
            pairs+=arr[i]*arr[60-i];

        return pairs;
    }
};

int main()
{
    int n;
    cout<<" Songs: ";
    cin>>n;

    vector <int> time;
    int x;

    for(int i=0;i<n;i++)
    { 
        cin>>x;
        time.push_back(x);
    }

    Solution s;

    cout<<" ANS:"<<s.numPairsDivisibleBy60(time);
}