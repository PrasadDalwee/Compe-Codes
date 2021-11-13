#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gridChallenge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY grid as parameter.
 */
 void print(vector<char> x)
 {
     for(auto i: x)
        cout<<i;
    cout<<endl;
 }

string gridChallenge(vector<string> grid) {
    vector<vector<char>> arr(grid.size());
    for(int i=0; i<grid.size();i++)
    {
        for ( auto j: grid[i])
            arr[i].push_back(j);
        sort(arr[i].begin(),arr[i].end());
    }
    
    vector<char> temp(arr.size());
    vector<char> sorted(arr.size());
    int check=0;
    
    for(int y=0; y<arr[0].size(); y++)
    {
        for( int x=0; x<arr.size(); x++)
        {
            temp[x]=arr[x][y];
        }
        //print(temp);
        sorted=temp;
        //print(sorted);
        sort(sorted.begin(),sorted.end());
        //print(sorted);
       // cout<<endl<<endl;
        if(sorted==temp)
            check++;
    }
    
    if( check==arr[0].size()) return "YES";
    return "NO";
    
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

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

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
