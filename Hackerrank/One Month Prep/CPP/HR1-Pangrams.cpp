#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    
    int a=int('a');
    int check[26]={0};
    char x;    
    int diff;
    
    for( auto i: s)
    {   
        x=tolower(i);   //converting each letter to lowercase
        diff=int(x)-a;
        if(diff<=26 and diff>=0)    //if letter between
            check[diff]=1;   
    }   
    
    for( auto i: check)
        if(i==0)
            return "not pangram";

    
    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
