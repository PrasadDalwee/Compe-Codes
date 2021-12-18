#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'counterGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts LONG_INTEGER n as parameter.
 */
vector<double> powers(1,1);

long div(long n)
{
    for(int i=0; i<powers.size();i++)
    {
        if(powers[i]>n)
            return n-powers[i-1];
        else if(powers[i]==n)
            return n/2;
    }
    
    return -1;
}
string counterGame(long n) {
    double x=2;
    for(int i=1;i<64;i++)//power array
    {
        powers.push_back(x);
        x=x*2;
    }
    
    while(true)
    {
        cout<<n<<endl;
        if(n==1)
            return "Richard";//louise loses
        n=div(n);
        
        cout<<n<<endl;
        if(n==1)
            return "Louise";
        n=div(n);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
