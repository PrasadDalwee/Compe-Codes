#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n,temp=0;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    for( int i=1;i<n-1;i++)
    {
        if(arr[i-1]>=arr[i] && arr[i]<=arr[i+1])
        {
            temp=1;
            break;
        }
    }
    
    if(temp==1) cout<<"No";
    else cout<<"Yes";
 
    return 0;
}
