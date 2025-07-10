#include <bits/stdc++.h>

#include "UTILS/helper.h"

using namespace std;

class Solution {
 public:
  int maxEvents(vector<vector<int>> &events) {
    int mxEvents = 0;

    // day used
    unordered_map<int, bool> mp;

    // // sort the events in increasing order of end_times

    // sort(events.begin(), events.end(), [](const auto &a, const auto &b) {
    //   return a[1] < b[1];
    // });

    // sort the events in increasing order of start_time

    sort(events.begin(), events.end(), [](const auto &a, const auto &b) {
      if (a[0] == b[0]) {
        return a[1] < b[1];
      }

      return a[0] < b[0];
    });

    print2DVector(events);

    // min heap

    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    priority_queue<pair<int, int>> mxHeap;

    for (auto &event : events) {
      if (mxHeap.size() == 0) {
        mxHeap.push({event[1], event[0]});
        mp[event[0]] = true;
        // { end_time, start_time}
      } else {
        auto tp = mxHeap.top();

        int tp_end_time = tp.first;

        if (tp_end_time >= event[0] && tp_end_time <= event[1]) {
          // mxHeap.push({event[1], event[0]});

          // choose a day in the start and end_time range
          for (int i = tp_end_time; i <= event[1]; i++) {
            // day i has not be taken yet
            if (mp.count(i) == 0) {
              mp[i] = true;
              mxHeap.push({event[1], event[0]});

              break;
            }
          }

        } else if (tp_end_time < event[0]) {
          mp[event[0]] = true;  // marking as the starting day as d
          // as we should not use this day again in the future
          mxHeap.push({event[1], event[0]});
        }
      }
    }

    cout << "map : " << endl;
    printMap(mp);

    mxEvents = mxHeap.size();

    while (!mxHeap.empty()) {
      auto tp = mxHeap.top();
      mxHeap.pop();
      cout << tp.first << "  " << tp.second << endl;
    }

    return mxEvents;
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

  vector<vector<int>> events = parse2dVectorInput(line);

  print2DVector(events);
  cout << "Input ends here-----------" << endl;

  int ans = sol.maxEvents(events);

  cout << "ans : " << ans << endl;

  return 0;
}