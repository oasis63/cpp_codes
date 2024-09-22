#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string &str, char delim) {
    vector<string> tokens;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    string str = "Hello, world!";
    char delim = ',';

    vector<string> tokens = split(str, delim);

    for (const string &token : tokens) {
        cout << token << endl;
    }

    return 0;
}