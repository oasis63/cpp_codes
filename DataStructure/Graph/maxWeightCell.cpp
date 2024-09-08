class Solution {
  public:
    int maxWeightCell(int n, vector<int> edge) {

        int maxSum = 0;
        int ind = 0;
        int val = 0;
        map<int, int> mp;

        for (int i = 0; i < edge.size(); i++) {
            val = edge[i];
            if (val != -1 && val < n) {
                mp[val] += i;
            }
        }

        for (auto ref : mp) {
            int dest = ref.first;
            if (ref.second >= maxSum) {
                maxSum = ref.second;
                ind = dest;
            }
        }

        return ind;
    }
};