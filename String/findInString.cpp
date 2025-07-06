class Solution {
  private:
    const string vowels = "aeiouAEIOU";

  public:
    bool hasVowels(char c) { return vowels.find(c) != string::npos; }

    string reverseVowels(string s) {
        int r = s.length() - 1;
        int l = 0;

        while (l < r) {
            if (hasVowels(s[l]) && hasVowels(s[r])) {
                swap(s[l], s[r]);
                l++;
                r--;
            } else if (!hasVowels(s[l])) {
                l++;
            } else {
                r--;
            }
        }
        return s;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
