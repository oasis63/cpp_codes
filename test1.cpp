#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  int earliestFinishTime(vector<int>& landStartTime,
                         vector<int>& landDuration,
                         vector<int>& waterStartTime,
                         vector<int>& waterDuration) {
    int n = landStartTime.size();
    int m = waterStartTime.size();

    int mn_time = INT_MAX;

    // start land first
    for (int i = 0; i < n; i++) {
      int end_time = landStartTime[i] + landDuration[i];
      for (int j = 0; j < m; j++) {
        if (waterStartTime[j] <= end_time) {
          mn_time = min(mn_time, end_time + waterDuration[j]);
        } else {
          // the ride has not started yet
          mn_time =
              min(mn_time, waterStartTime[j] + waterDuration[j]);
        }
      }
    }

    // start water first

    for (int i = 0; i < m; i++) {
      int end_time = waterStartTime[i] + waterDuration[i];

      for (int j = 0; j < n; j++) {
        if (landStartTime[j] <= end_time) {
          mn_time = min(mn_time, end_time + landDuration[j]);
        } else {
          // the ride has not started yet
          mn_time = min(mn_time, landStartTime[j] + landDuration[j]);
        }
      }
    }

    return mn_time;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_io_files("input.txt", "output.txt");

  Solution sol;

  string line;
  getline(cin, line);

  vector<int> nums = parseVector<int>(line);

  printVect(nums);

  cout << "Solution started ...." << endl;
  int ans = sol.solve(nums);

  cout << "ans : " << ans << endl;

  return 0;
}