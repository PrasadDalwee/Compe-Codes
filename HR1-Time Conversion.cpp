#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string hour,min,sec,zone;
    int hr;
    hour=s.substr(0,2);
    min=s.substr(3,2);
    sec=s.substr(6,2);
    zone=s.substr(8,2);
    //cout<<hr<<"\t"<<min<<"\t"<<sec<<"\t"<<zone<<endl;
    if(zone=="AM")
    {
        if(hour=="12")
            hour="00";
    }
    
    else {
        if(hour!="12")
            {
                hr=stoi(hour);
                hr+=12;
                hour=to_string(hr);
            }
    }
    // cout<<hr<<"\t"<<min<<"\t"<<sec<<endl;
    return hour+":"+min+":"+sec ;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
