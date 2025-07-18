
#include <bits/stdc++.h>
using namespace std;

// 1. Finding the maximum element in a vector

vector<int>
    arr = {1, 2, 3, 4}

int max_arr = *max_element(arr.begin(), arr.end());

// 2. Finding the sum of all elements in a vector

vector<int>
    arr = {1, 2, 3, 4}

int sum = accumulate(arr.begin(), arr.end(), 0);

// 3. Binary search on the vector

vector<int>
    arr = {1, 2, 3, 4}

int target = 4;

bool found = binary_search(arr.begin(), arr.end(), target);

// 4. Reverse the vector

vector<int>
    arr = {1, 2, 3, 4}

reverse(arr.begin(), arr.end())

    // 5. Count occurrences of an element in a vector

    vector<int>
        arr = {1, 3, 4, 2, 2, 3, 4}

int value = 2;

int count_elem = count(arr.begin(), arr.end(), value);

// 6. Concatenate two vectors

vector<int>
    arr = {1, 3, 4, 2, 2, 3, 4} vector<int> arr2 = {5, 6, 7};

vector<int> combined;
combined.insert(combined.end(), arr.begin(), arr.end());
combined.insert(combined.end(), arr2.begin(), arr2.end());

// 7. Sort the given vector

vector<int>
    arr = {1, 7, 4, 2, 0, 3, 4}

// ascending order
sort(arr.begin(), arr.end());

// descending order
sort(arr.end(), arr.begin());

// 8. Remove an element from the vector

vector<int>
    arr = {1, 7, 4, 2, 0, 3, 4}

int value_to_remove = 4;

arr.erase(remove(arr.begin(), arr.end(), value_to_remove), arr.end());

// 9. Check if an element exists in the vector

vector<int>
    arr = {1, 7, 4, 2, 0, 3, 4}

bool exists = find(arr.begin(), arr.end(), 4) != arr.end();

// 10. Finding the minimum element in a vector

vector<int>
    arr = {1, 2, 3, 4}

int max_arr = *min_element(arr.begin(), arr.end());