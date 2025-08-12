#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

/*



class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {

        int n = arr.size();
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        int temp_sum = arr[0];

        for (int i = 1; i < n; i++) {
            int start_ind = 0;
            // even length
            if ((i + 1) % 2 == 0) {
                start_ind = 1;
            } else {
                start_ind = 2;
                temp_sum += prefix[i];
            }

            for (int j = start_ind; j < i; j += 2) {
                temp_sum += (prefix[i] - prefix[j - 1]);
            }

            temp_sum += prefix[i] - prefix[i - 1];
        }

        return temp_sum;
    }
};


*/

class Solution {
 public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    int ans = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      int leftSub = i + 1;   // choices to have the  arr[i] in subarray
      int rightSub = n - i;  // choices to have the arr[i] in subaaray
      int total = leftSub * rightSub;
      int odd = (total + 1) / 2;
      ans += arr[i] * odd;
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  Solution sol;

  string line;
  getline(cin, line);

  vector<int> nums = parseVector<int>(line);

  printVect(nums);

  cout << "Solution started ...." << endl;
  int ans = sol.sumOddLengthSubarrays(nums);

  cout << "ans : " << ans << endl;

  return 0;
}