class Solution {
  public:
    void solve(vector<vector<int>> &ans, vector<int> &res, int curr, int n,
               int k) {
        if (res.size() == k) {
            ans.push_back(res);
            return;
        }
        for (int i = curr; i <= n; i++) {
            res.push_back(i);
            solve(ans, res, i + 1, n, k);
            res.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> res;
        solve(ans, res, 1, n, k);
        return ans;
    }
};