//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int maxInRange(int *arr, int start, int end) {
        int maxVal = INT_MIN;
        for (int i = start; i <= end; i++) {
            maxVal = max(maxVal, arr[i]);
        }
        return maxVal;
    }

    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k) {
        // your code here
        vector<int> ans;

        // find maximum of first k  length subarray
        int currMax = INT_MIN;
        for (int i = 0; i < k; i++) {
            currMax = max(currMax, arr[i]);
        }
        ans.push_back(currMax);

        int windowMax = currMax;
        for (int i = k; i < n; i++) {

            int prevElem = arr[i - k];
            int newElem = arr[i];
            // cout << "p : " << prevElem << "  n : " << newElem << endl;

            if (windowMax != prevElem) {
                windowMax = max(windowMax, newElem);
            } else {
                // find the max in the new range
                int maxVal = maxInRange(arr, i - k, i);
                windowMax = maxVal;
            }

            ans.push_back(windowMax);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int n = 2; // 9;
    int k = 1; // 3;

    // int arr[n] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int arr[n] = {1, -1};

    Solution ob;
    vector<int> res = ob.max_of_subarrays(arr, n, k);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
// } Driver Code Ends
