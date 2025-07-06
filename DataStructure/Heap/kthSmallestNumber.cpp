#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define uli unsigned long int

class Util {
  public:
    template <typename T> void printSet(const set<T> &s) {
        for (const auto &element : s) {
            cout << element << " ";
        }
        cout << endl;
    }
    template <typename T> void printVector(const vector<T> &v) {
        for (const auto &element : v) {
            cout << element << " ";
        }
        cout << endl;
    }

    template <typename T> void print2DVector(const vector<vector<T>> &vec) {
        for (const auto &row : vec) {
            for (const auto &element : row) {
                cout << element << " ";
            }
            cout << endl;
        }
    }
};

Util util;

void printHeap(
    // priority_queue<string, vector<string>, greater<string>> myMinHeap) {
    priority_queue<string> myMinHeap) {
    // Print and remove elements from the min-heap
    cout << "Min-Heap elements: ";
    while (!myMinHeap.empty()) {
        cout << myMinHeap.top() << " ";
        myMinHeap.pop();
    }
    cout << std::endl;
}

class Solution {
  public:
    int findKthNumber(int n, int k) {

        vector<string> nums;

        for (int i = 1; i <= n; i++) {
            nums.push_back(to_string(i));
        }

        int kthAns = 1;

        // sort(nums.begin(), nums.end());
        util.printVector(nums);
        // kthAns = stoi(nums[k - 1]);

        // priority_queue<string, vector<string>, greater<string>> myMinHeap;
        priority_queue<string> myMaxHeap; // maxHeap

        for (int i = 0; i < k && i < n; i++) {
            myMaxHeap.push(nums[i]);
        }

        int v_size = nums.size();

        for (int i = k; i < v_size; i++) {
            string top1 = myMaxHeap.top();
            bool comparet = nums[i] < top1;
            cout << "nums[i] " << nums[i] << "  top : " << top1
                 << " isLessThan " << comparet << endl;
            if (nums[i] < myMaxHeap.top()) {
                myMaxHeap.pop();
                myMaxHeap.push(nums[i]);
            }
        }

        printHeap(myMaxHeap);

        kthAns = stoi(myMaxHeap.top());

        return kthAns;
    }

    // more efficient solution
    int findKthNumber2(int n, int k) {
        priority_queue<int, vector<int>, greater<int>> myMinHeap;

        for (int i = 1; i <= n; i++) {
            if (myMinHeap.size() < k) {
                myMinHeap.push(i);
            } else if (i < myMinHeap.top()) {
                myMinHeap.pop();
                myMinHeap.push(i);
            }
        }

        return myMinHeap.top();
    }
};
Solution sol;

int main() {

    int n = 13, k = 2;
    int res = sol.findKthNumber(n, k);

    cout << "res : " << res << endl;

    return 0;
}

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();