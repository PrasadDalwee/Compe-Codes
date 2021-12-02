              // I have not used two stacks
              // this code could have been way easier if vecctors were used

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    int arr[n], head=0, tail=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            int val;
            cin>>val;
            arr[tail]=val;
            tail++;
        }
        
        if(x==2)
        {
            head++;
        }
        
        if(x==3)
        {
            cout<<arr[head]<<endl;
        }
    }   
    return 0;
}

