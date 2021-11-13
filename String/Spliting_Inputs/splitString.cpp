#include<bits/stdc++.h>
using namespace std;

vector<string> split_string(string);    // declaration of the method


int main(){
   
    string nm_temp;  
    getline(cin, nm_temp);      // input a string of numbers 

    vector<string> nm = split_string(nm_temp);    

    
    int len = nm.size();

    for(int i=0;i<len;i++){
    	cout<<nm[i]<<endl;
    }


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
