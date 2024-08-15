//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthsmallest(const vector<int> &A, int B);
};

int Solution::kthsmallest(const vector<int> &A, int B) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = A.size();
    for (int i = 0; i < n; i++) {
        pq.push(A[i]);
    }

    while (!pq.empty() && B > 1) {
        cout << pq.top() << endl;
        pq.pop();
        B--;
    }

    if (pq.empty())
        return -1;

    return pq.top();
}

int main() {
    Solution sol;

    int B = 3;
    vector<int> vect = {2, 1, 4, 3, 2};

    int res = sol.kthsmallest(vect, B);
    cout << "res : " << res << endl;

    return 0;
}
