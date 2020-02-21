#include<bits/stdc++.h>
using namespace std;

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';       // change this delimeter .. according to need ... like ->   ,

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


int main(){

    string str;
    getline(cin,str);

//    int sum;cin>>sum;

    vector<string> inputString = split_string(str);
    vector<int> vect;

    for(string str : inputString){
        stringstream ss(str);
        int el;
        ss>>el;
        vect.push_back(el);
    }

    for(int i : vect){
        cout<<i<<endl;
    }

}




















