#include <bits/stdc++.h>
using namespace std;

// Function to implement monotonic increasing stack
vector<int> monotonicIncreasing(vector<int> &nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> result;

    // Traverse the array
    for (int i = 0; i < n; ++i) {
        // While stack is not empty AND top of stack is more
        // than the current element
        while (!st.empty() && st.top() > nums[i]) {
            // Pop the top element from the
            // stack
            st.pop();
        }

        // Push the current element into the stack
        st.push(nums[i]);
    }

    // Construct the result array from the stack
    while (!st.empty()) {
        result.insert(result.begin(), st.top());
        st.pop();
    }

    return result;
}

int main() {
    // Example usage:
    // vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};

    cout << "input nums : ";
    for (int elem : nums)
        cout << elem << " ";
    cout << endl;
    vector<int> result = monotonicIncreasing(nums);
    cout << "Monotonic increasing stack: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
