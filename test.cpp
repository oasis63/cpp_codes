#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int len = nums.size();
        vector<int> vect;

        bool visitedLast = false;

        priority_queue<int> pq;

        for (int i = 0; i < len; i++) {

            pq.push(nums[i]);

            cout << nums[i] << endl;

            if (pq.size() == k) {
                vect.push_back(pq.top());
                pq.pop();
            }
        }
        return vect;
    }
};

int main() {

    Solution s;

    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = s.maxSlidingWindow(nums, k);

    cout << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}