class Solution {
 public:
  vector<int> generateSquares(int n) {
    vector<int> ps;
    int num = 1;
    while (true) {
      int tp = num * num;
      if (tp > n) break;
      ps.push_back(tp);
      num++;
    }
    return ps;
  }

  // solving it similar to minimum coin change problem
  int topDownAproach(vector<int>& deno, vector<int>& dp, int amount) {
    if (amount == 0) return 0;

    if (amount < 0) return INT_MAX;

    if (dp[amount] != -1) return dp[amount];

    int ways = INT_MAX;

    for (int coin : deno) {
      int subprob = topDownAproach(deno, dp, amount - coin);

      if (subprob != INT_MAX) {
        ways = min(ways, subprob + 1);
      }
    }

    return dp[amount] = ways;
  }

  int numSquares(int amount) {
    // generate all the perfect squares to the given number
    vector<int> ps = generateSquares(amount);

    // vector<int> dp(amount + 1 , -1);
    // int result = topDownAproach(ps, dp, amount);

    // bottom up approach .. tabulation

    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
      for (int coin : ps) {
        int reduced_amount = i - coin;
        if (reduced_amount >= 0 && dp[reduced_amount] != INT_MAX) {
          dp[i] = min(dp[i], dp[reduced_amount] + 1);
        }
      }
    }

    return dp[amount];
  }
};