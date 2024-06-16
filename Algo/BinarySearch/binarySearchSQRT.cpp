#include <bits/stdc++.h>
using namespace std;

// find square root using binary search logic

class Solution {
  public:
    int mySqrt(int x) {
        int ans = 0;
        int left = 1, right = x, mid;

        while (left <= right) {
            mid = left + (right - left) / 2;

            if (mid <= x / mid) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;
    int x = 121;
    cout << obj.mySqrt(x) << endl;

    return 0;
}