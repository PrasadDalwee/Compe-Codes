/*
Function code:

void plusMinus(vector<int> arr) {
    int p=0,z=0,n=0,t=0;
    for(auto i: arr)
    {
        if(i>0)p++;
        else if(i==0)z++;
        else if (i<0) n++;
        
        t++;
    }
    float P=float(p);
    float N=float(n);
    float Z=float(z);
    float T=float(t);
    if(p==t || n==t || z==t)                  
        cout<<p/t<<endl<<n/t<<endl<<z/t;
    else 
    {
    cout<<setprecision(6)<< P/T - p/t<<endl;    
    cout<<setprecision(6)<< N/T - n/t<<endl;
    cout<<setprecision(6)<< Z/T - z/t;
    }
    
} 
*/



//Full code:

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void plusMinus(vector<int> arr) {
    int p=0,z=0,n=0,t=0;
    for(auto i: arr)
    {
        if(i>0)p++;
        else if(i==0)z++;
        else if (i<0) n++;
        
        t++;
    }
    float P=float(p);
    float N=float(n);
    float Z=float(z);
    float T=float(t);
    if(p==t || n==t || z==t)          // edge case where ratio of one item is one and rest zero
        cout<<p/t<<endl<<n/t<<endl<<z/t;
    else 
    {
    cout<<setprecision(6)<< P/T - p/t<<endl;        //use setpresicion() to limit the decimal places
    cout<<setprecision(6)<< N/T - n/t<<endl;
    cout<<setprecision(6)<< Z/T - z/t;
    }
    
} 

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
