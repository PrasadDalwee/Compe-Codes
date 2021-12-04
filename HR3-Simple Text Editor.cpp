#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int Q;
    cin>>Q;
    int c,k;
    string S,W;
    vector <string> Sprev;
    
    while (Q>0) 
    {
        cin>>c;
        if(c==1)    //insert
        {
            cin>>W;
            Sprev.push_back(S);
            S=S+W;
        }
        
        else if(c==2)   //delete
        {
            cin>>k;
            Sprev.push_back(S);
            S=S.substr(0,S.size()-k);
        }
        
        else if(c==3)   //print
        {
            cin>>k;
            cout<<S[k-1]<<endl;
        }
        
        else            //undo
        {
            S=Sprev[Sprev.size()-1];
            Sprev.pop_back();
        }
        
        Q--;
    }
    
    return 0;
}
