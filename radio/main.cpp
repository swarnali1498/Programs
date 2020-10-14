#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the hackerlandRadioTransmitters function below.
int hackerlandRadioTransmitters(vector<int> x, int k)
{
    sort(x.begin(),x.end());
    int i,j,c=0,count=0;
    int n=x.size();
    for(i=0;i<x.size();i++)
    {
       // cout<<"In "<<i<<endl;
        c=0;
        while(c<k)
        {
            if(i+1<n && x[i+1]-x[i]<k-c)
            {
                c=c+x[i+1]-x[i];
                i++;
            }
            else if(i+1<n && x[i+1]-x[i]==k-c)
            {
                i++;
                break;
            }
            else
            {
                break;
            }
        }
       // cout<<x[i]<<endl;
        count++;
        c=0;
        while(c<k)
        {
            if(i+1<n && x[i+1]-x[i]<k-c)
            {
                c=c+x[i+1]-x[i];
                i++;
            }
            else if(i+1<n && x[i+1]-x[i]==k-c)
            {
                i++;
                break;
            }
            else
            {
                break;
            }
         //   cout<<"i="<<i<<endl;
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string x_temp_temp;
    getline(cin, x_temp_temp);

    vector<string> x_temp = split_string(x_temp_temp);

    vector<int> x(n);

    for (int i = 0; i < n; i++) {
        int x_item = stoi(x_temp[i]);

        x[i] = x_item;
    }

    int result = hackerlandRadioTransmitters(x, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
