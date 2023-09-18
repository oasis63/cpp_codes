#include <bits/stdc++.h>
using namespace std;

class Utility {
   public:
    static int binarySearch(vector<int> vect, int key) {
        int n = vect.size();
        int beg = 0, end = n - 1, mid;
        while (beg <= end) {
            mid = (beg + end) / 2;

            if (vect[mid] == key) {
                return mid;
            }
            // check if the left half is sorted
            if (vect[beg] <= vect[mid]) {
                if (vect[beg] <= key < vect[mid]) {
                    beg = mid - 1;
                } else {
                    beg = mid + 1;
                }
            } else {
                if (vect[mid] < key <= vect[end]) {
                    end = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

class Solution {
   public:
    int binarySearch(vector<int> vect, int key) {
        int n = vect.size();
        int beg = 0, end = n - 1, mid;
        while (beg <= end) {
            mid = (beg + end) / 2;

            if (vect[mid] == key) {
                return mid;
            }
            // check if the left half is sorted
            if (vect[beg] <= vect[mid]) {
                if (vect[beg] <= key && key < vect[mid]) {
                    end = mid - 1;
                } else {
                    beg = mid + 1;
                }
            } else {
                if (vect[mid] < key && key <= vect[end]) {
                    beg = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        // int len = nums.size();
        // for (int i = 0; i < len; i++) {
        //     if (nums[i] == target) return i;
        // }
        // return -1;

        return binarySearch(nums, target);
    }
};

int main() {
    cout << "main  " << endl;

    Solution s;

    int target = 0;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    cout << s.search(nums, target) << endl;

    return 0;
}