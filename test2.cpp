#include <bits/stdc++.h>
using namespace std;

class Utility {
   public:
    vector<int> binarySearch(vector<int> vect, int beg, int end, int key) {
        vector<int> ans(2);
        int n = vect.size();
        bool flag = true;
        // int beg = 0, end = n - 1, mid;
        // base cases

        vector<int> res;
        if (n == 0) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        } else if (n == 1) {
            if (vect[0] == key) {
                res.push_back(0);
                res.push_back(0);

            } else {
                res.push_back(-1);
                res.push_back(-1);
            }
            ans.push_back(0);
            ans.push_back(0);

            return res;
        } else if (vect[0] == key && vect[n - 1] == key) {
            // ans.push_back(0);
            // ans.push_back(n - 1);
            // return ans;

            res.push_back(0);
            res.push_back(n - 1);
            return res;
        }

        int mid;
        while (beg <= end) {
            mid = (beg + end) / 2;
            cout << "mid : " << mid << " vect[mid] : " << vect[mid] << endl;

            if (vect[mid] == key) {
                if (mid == 0) {
                    cout << "firstttt" << endl;
                    ans.push_back(mid);
                    beg = mid + 1;
                } else if (mid == n - 1) {
                    cout << "secondddd" << endl;
                    ans.push_back(mid);
                    end = mid - 1;
                } else {
                    cout << "33333" << endl;
                    if (vect[mid - 1] != key) {
                        cout << "444444" << endl;
                        ans.push_back(mid);
                        beg = mid + 1;
                    } else if (vect[mid + 1] != key) {
                        cout << "55555" << endl;
                        ans.push_back(mid);
                        end = mid - 1;
                    } else {
                        int temp1 = mid;
                        int temp2 = mid;
                        bool flag1 = false;
                        bool flag2 = false;

                        while (temp1 >= 0 && vect[temp1] == key) {
                            temp1--;
                            flag1 = true;
                            cout << "temp1 " << temp1 << endl;
                        }
                        if (flag1) temp1++;
                        cout << "temp1 " << temp1 << endl;

                        while (temp2 <= n - 1 && vect[temp2] == key) {
                            temp2++;
                            flag2 = true;
                            cout << "temp2 " << temp2 << endl;
                        }
                        if (flag2) temp2--;
                        cout << "temp2 " << temp2 << endl;

                        ans = {};
                        ans.push_back(temp1);
                        ans.push_back(temp2);
                        return ans;
                    }
                }

                if (ans.size() == 4) {
                    cout << "666666" << endl;
                    flag = false;
                    break;
                }

            } else if (key > vect[mid]) {
                cout << "77777" << endl;
                beg = mid + 1;
            } else {
                cout << "888888" << endl;
                end = mid - 1;
            }
        }

        if (ans.size() == 3) {
            res.push_back(ans[2]);
            res.push_back(ans[2]);
            // ans.push_back(ans[0]);
            // return res;
        } else if (flag) {
            res.push_back(-1);
            res.push_back(-1);
            ans = {-1, -1};
        } else {
            res.push_back(ans[2]);
            res.push_back(ans[3]);
        }
        return res;
    }
};

Utility util;
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = util.binarySearch(nums, 0, nums.size() - 1, target);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution s;

    int target = 1;
    // vector<int> nums = {1, 2, 3, 3, 3,3, 4, 5, 9};  //{5, 7, 7, 8, 8, 10};
    // //{3, 3, 3};
    // vector<int> nums = {0, 1, 1, 1, 2, 2, 2, 2, 3, 3,
    //                     4, 4, 5, 5, 6, 6, 7, 7, 8, 9};
    vector<int> nums = {0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 4};
    for (auto elm : nums) {
        cout << elm << "   ";
    }
    cout << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << i << "   ";
    }
    cout << endl;
    cout << endl;

    vector<int> ans = s.searchRange(nums, target);
    for (auto val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}