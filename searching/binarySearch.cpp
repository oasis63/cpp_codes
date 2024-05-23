// binary search in C++

#include <bits/stdc++.h>
using namespace std;

void binarySearch(int a[], int n, int key) {
    int beg = 0, end = n - 1, mid;
    int found = 0;

    while (beg <= end) {
        mid = (beg + end) / 2;

        if (a[mid] == key) {
            found = 1;
            cout << "found" << endl;
            break;
        }

        else if (a[mid] > key) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }

    if (found == 0)
        cout << "Not present" << endl;
}

int main() {
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int key;
    cout << "Enter a element to be searched in the array" << endl;
    cin >> key;

    binarySearch(a, n, key);
}