#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

class Solution {
 public:
  const int MOD = 1e9 + 7;
  string one_string = "";
  string zero_string = "";

  vector<int> dp;

  string generator(char type, int n) {
    string st = "";
    for (int i = 0; i < n; i++) {
      st.push_back(type);
    }
    return st;
  }

  int buildGoodStrings(int low, int high, int zero, int one, string st) {
    int st_len = st.length();

    if (st_len > high) return 0;

	if(dp[st_len] != -1){
		cout<<" hit at st_len : " << st_len << endl;
		return dp[st_len];
	}

    if (st_len >= low && st_len <= high) {
      return dp[st_len] = 1 + buildGoodStrings(low, high, zero, one, st + zero_string) +
             buildGoodStrings(low, high, zero, one, st + one_string);
    }

    return dp[st_len] = buildGoodStrings(low, high, zero, one, st + zero_string) +
           buildGoodStrings(low, high, zero, one, st + one_string);
  }

  int countGoodStrings(int low, int high, int zero, int one) {
    int ans = 0;

	dp.resize(100001,-1);

    string st = "";

    zero_string = generator('0', zero);
    one_string = generator('1', one);

    int res = buildGoodStrings(low, high, zero, one, st);

    cout << " res : " << res << endl;

    return res % MOD;
  }
};

void generateFibs(vector<int> &vect) {
  int n = vect.size();
  for (int i = 2; i < n; i++) {
    vect[i] = vect[i - 1] + vect[i - 2];
  }
}

int main() {
  //   vector<int> fibs = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

    // int low = 3;
    // int high = 3;
    // int zero = 1;
    // int one = 1;

  //  int x = low = high;

  Solution sol;

//   int low = 2, high = 3, zero = 1, one = 2;

  int low = 200, high = 200, zero = 10, one = 1;

  int n = 20;

  vector<int> fibs(n, 0);
  fibs[0] = 1;
  fibs[1] = 2;
  generateFibs(fibs);

  cout << sol.countGoodStrings(low, high, zero, one) << endl;

  //   for (int i = 1; i < n; i++) {
  //     int low = i, high = i, zero = 5, one = 4;

  //     int range = high - low;
  //     int group = one + zero;

  //     int res = sol.countGoodStrings(low, high, zero, one);
  //     cout << "low " << low << " high : " << high << " zero : " << zero
  //          << " one : " << one << " group_size : " << group << " res : " <<
  //          res
  //          << "  fibs[" << i << "] : " << fibs[i - 1] << endl;
  //   }

  return 0;
}