/*
    ॐ नमः शिवाय | 
*/

#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define uli unsigned long int
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}


class Util {
  public:
    template <typename T> void printSet(const set<T> &s) {
        for (const auto &element : s) {
            cout << element << " ";
        }
        cout << endl;
    }
    template <typename T> void printVector(const vector<T> &v) {
        for (const auto &element : v) {
            cout << element << " ";
        }
        cout << endl;
    }
    template <typename T> void print2DVector(const vector<vector<T>> &vec) {
        for (const auto &row : vec) {
            for (const auto &element : row) {
                cout << element << " ";
            }
            cout << endl;
        }
    }
};

Util util;

class Solution {
  public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();

        int carry = 0;

        int i = len1-1 , j = len2-1;

        string ans = "";
        int n1, n2, sum;

        while( i >=0 && j >= 0){
            n1 = num1[i]-'0';
            n2 = num2[j] -'0';
            sum = n1 + n2 + carry;
            carry = sum/10;
            sum = sum%10;
            ans = to_string(sum) + ans;
            i--;
            j--;
        }

        while( i >=0 ){
            n1 = num1[i]-'0';
            sum = n1 + carry;
            carry = sum/10;
            sum = sum%10;
            ans = to_string(sum) + ans;
            i--;
        }

        while( j >=0 ){
            n2 = num2[j] -'0';
            sum = n2 + carry;
            carry = sum/10;
            sum = sum%10;
            ans = to_string(sum) + ans;
            j--;
        }

        if( carry )   ans = to_string(carry) + ans;

        return ans;

    }
};

Solution sol;

int main() {
    freopen("inputs.txt","r",stdin);
    freopen("oututs.txt","w",stdout);

    string res = sol.solve(num1 ,num2);
    bug(res);
    return 0;
}

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();