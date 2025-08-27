
class Solution {
 public:
  int countDistinct(vector<int>& nums, int k, int p) {
    int res = 0;
    int n = nums.size();

    set<vector<int>> st;

    unordered_set<long long> seen;

    long long base = 200003;
    long long MOD = 1e9 + 7;

    cout << "Printing the subarrays \n";
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      // vector<int> vect;
      long long hash = 0;
      for (int j = i; j < n; j++) {
        // vect.push_back(nums[j]);
        if (nums[j] % p == 0) {
          cnt++;
        }
        if (cnt <= k) {
          res++;
          // sort(vect.begin(), vect.end());

          // polynomial rolling hash

          hash = (hash * base + nums[j]) % MOD;

          seen.insert(hash);
        } else {
          break;
        }
      }
    }

    bug(seen.size());

    return res;
  }
};