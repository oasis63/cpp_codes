class Solution {
  public:
    vector<string> split(const string &str, char delimiter) {
        vector<string> tokens;
        stringstream ss(str);
        string token;

        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }

        return tokens;
    }

    bool wordPattern(string pattern, string s) {
        char delimiter = ' ';
        vector<string> result = split(str, delimiter);
    }
};