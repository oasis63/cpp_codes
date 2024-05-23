//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        // Your code here

        vector<int> ans = {};

        // slding window problem

        int start = 0, end = 0;
        int curr_sum = 0;

        while (end < n) {

            // add till sum value s
            while (curr_sum < s && end < n) {
                curr_sum += arr[end++];
            }

            // curr_sum matches s return start and end
            if (curr_sum == s) {
                // cout << " sum matched : at : " << start << "  " << (end - 1)
                //      << endl;
                ans.push_back(start + 1);
                ans.push_back(end);
                break;
            }

            // if curr_sum > s then ++start

            while (curr_sum > s && start < n) {
                curr_sum -= arr[start++];
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
