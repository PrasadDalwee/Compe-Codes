#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) 
{
    if (s.size()==1 || s.size()==2)
        return "YES";
    
    vector<int> q('z'-'a'+1,0);
    
    for(auto i: s)
        q[i-'a']++;
    
    sort(q.begin(),q.end());
    
    vector<vector<int>>m;
    int c=0;
    int y=0;
    for( auto i: q)
    {
        if(i!=0)
        {
            y=0;c=0;
            while(y<m.size())
            {
                if(i==m[y][0])
                {
                    c=1;
                    m[y][1]++;
                    break;
                }
                y++;
            }
            if(c==0)
                m.push_back({i,1});
        }
    }
    
    for( auto i: m)
    {
        cout<<i[0]<<" "<<i[1]<<endl;
    }
    
    if(m.size()==1)
        return "YES";
    
    if(m.size()<3)
    {
        
        if(m[0][0]==1 && m[0][1]==1)
            return "YES";
        
        if(m[1][1]==1 && m[1][0]-m[0][0]==1)
            return "YES";
    }
        
    return "NO";
    
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

