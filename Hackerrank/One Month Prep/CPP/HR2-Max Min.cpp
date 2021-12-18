#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'maxMin' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int maxMin(int k, vector<int> arr) {
    int a=arr.size();
    vector <int> diff(a-1,0);
    
    sort(arr.begin(),arr.end());    //sort
    
    for (int i=0;i<a-1;i++)         //diff array
        diff[i]=arr[i+1]-arr[i];
        
    int window=0;
    for(int i=0;i<k-1;i++)          //first window
        window+=diff[i];
    
    int unfairness=window;
    for(int i=1;i<=a-k;i++)         //sliding window
    {
        cout<<unfairness<<endl;
        cout<<diff[i-1]<<" "<<window<<" "<<diff[i+k-2]<<endl;
        window=window-diff[i-1]+diff[i+k-2];
        if(window<unfairness)
            unfairness=window;
    }   
    
    return unfairness;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

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
