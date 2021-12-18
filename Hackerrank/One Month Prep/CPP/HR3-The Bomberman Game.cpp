#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */
//  void display(vector<string> grid)
// {
//     for(int i=0;i<grid.size();i++)
//         {for(int j=0;j<grid[0].size();j++)
//             cout<<grid[i][j];
//         cout<<endl;}
// }
void boom(vector<string> &grid,int n) 
{
    char a='O';
    if(n==1) a='1';
    
    for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[0].size();j++)
            if(grid[i][j]==a) 
               {
                    grid[i][j]='.';
                    if(j>0 && grid[i][j-1]!=a) grid[i][j-1]='.';
                    if(i>0 && grid[i-1][j]!=a) grid[i-1][j]='.';
                    if(i<grid.size()-1 && grid[i+1][j]!=a) grid[i+1][j]='.';
                    if(j<grid[0].size()-1 && grid[i][j+1]!=a) grid[i][j+1]='.'; 
               }
    // cout<<"out of boom\n";
    // display(grid);
}
void place(vector<string> &grid,int n)
{
    char a='O';
    if(n==1) a='1';
    
    for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[0].size();j++)
           { if(grid[i][j]=='.') 
                grid[i][j]=a;}

}
void show(vector<string> &grid)
{
    for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[0].size();j++)
            if(grid[i][j]!='.') 
                grid[i][j]='O';

}

vector<string> bomberMan(int n, vector<string> grid) 
{
    if(n==1)return grid;
    if(n==2)
    {
        place(grid,1);
        show(grid);
        return grid;
    }
    place(grid,1);

    int old_b=0,i=3;
    vector<string> temp;
    vector<int> ct;
    n=n%4;
    while(i<=n+4) //pattern repeats after every 4 seconds
    {
        if(i%2==1)
            {
                boom(grid,old_b);
                if(i==3)
                    temp=grid;
            }
        else {
            place(grid,old_b);
            old_b=(old_b+1)%2;
        }
        // cout<<i<<endl;
        // display(grid);
        // cout<<endl<<endl;
        // if(temp==grid)
        //     ct.push_back(i);
        i++;
    }
    show(grid);
    // for( auto i:ct)
    //     cout<<i;
    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
