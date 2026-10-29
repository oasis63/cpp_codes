
#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    int n;
    vector<long long> bit;

public:
    FenwickTree(int n) : n(n), bit(n + 1, 0) {}

    // Add delta to the element at index i.
    void update(int i, long long delta) {
        while (i <= n) {
            bit[i] += delta;
            i += (i & -i);
        }
    }

    // Sum of elements from index 1 to i.
    long long query(int i) {
        long long sum = 0;

        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }

        return sum;
    }

    // Sum of elements from index l to r.
    long long rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    vector<int> a = {2, 1, 3, 5, 4, 6, 7};
    int n = a.size();

    FenwickTree fw(n);

    // Fenwick Tree uses 1-based indexing.
    for (int i = 0; i < n; i++) {
        fw.update(i + 1, a[i]);
    }

    cout << fw.query(4) << '\n';       // 11
    cout << fw.rangeQuery(2, 5) << '\n'; // 13

    fw.update(3, 5);  // a[3] increases from 3 to 8

    cout << fw.query(4) << '\n';       // 16
}
